package concurrency;

import java.util.concurrent.Phaser;

public class PhaserMultiPhasePipeline {
    private final Phaser phaser = new Phaser(1);

    public void registerWorker() {
        phaser.register();
    }
}
