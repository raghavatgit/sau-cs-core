package concurrency;

import java.util.concurrent.CompletableFuture;

public class AsyncDataPipeline {
    public CompletableFuture<String> processData(String rawInput) {
        return CompletableFuture.supplyAsync(() -> rawInput.trim())
            .thenApply(s -> s.toUpperCase())
            .exceptionally(ex -> "DEFAULT");
    }
}
