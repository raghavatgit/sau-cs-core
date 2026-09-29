package org.sau.core;

import java.util.concurrent.ConcurrentSkipListMap;

public class ConcurrentSkipListBenchmark {
    public static void runBenchmark() {
        ConcurrentSkipListMap<Integer, String> map = new ConcurrentSkipListMap<>();
        for (int i = 0; i < 10000; i++) {
            map.put(i, "val-" + i);
        }
    }
}
