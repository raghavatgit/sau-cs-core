package concurrency;

import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ReadWriteLockFairScheduler {
    private final ReentrantReadWriteLock lock = new ReentrantReadWriteLock(true);
}
