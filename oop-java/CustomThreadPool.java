package org.sau.core;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class CustomThreadPool {
    private final BlockingQueue<Runnable> queue;
    private final WorkerThread[] workers;
    private volatile boolean isStopped = false;

    public CustomThreadPool(int numThreads, int maxQueueSize) {
        queue = new LinkedBlockingQueue<>(maxQueueSize);
        workers = new WorkerThread[numThreads];
        for (int i = 0; i < numThreads; i++) {
            workers[i] = new WorkerThread();
            workers[i].start();
        }
    }

    public void execute(Runnable task) throws InterruptedException {
        if (!isStopped) queue.put(task);
    }

    private class WorkerThread extends Thread {
        public void run() {
            while (!isStopped) {
                try {
                    Runnable task = queue.take();
                    task.run();
                } catch (InterruptedException ignored) {}
            }
        }
    }
}
