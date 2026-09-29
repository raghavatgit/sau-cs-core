package org.sau.core;

import java.nio.ByteBuffer;

public class MemoryMappedRingBuffer {
    private final ByteBuffer buffer;

    public MemoryMappedRingBuffer(int capacity) {
        this.buffer = ByteBuffer.allocateDirect(capacity);
    }

    public synchronized void writeByte(byte b) {
        if (buffer.hasRemaining()) buffer.put(b);
    }
}
