package org.sau.core;

public final class ImmutableVector {
    private final double x, y, z;

    public ImmutableVector(double x, double y, double z) {
        this.x = x; this.y = y; this.z = z;
    }

    public ImmutableVector add(ImmutableVector o) {
        return new ImmutableVector(this.x + o.x, this.y + o.y, this.z + o.z);
    }

    public double dot(ImmutableVector o) {
        return this.x * o.x + this.y * o.y + this.z * o.z;
    }
}
