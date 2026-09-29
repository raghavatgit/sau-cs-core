package structural;

interface WindowImpl { void drawRect(); }

abstract class Window {
    protected final WindowImpl impl;
    protected Window(WindowImpl impl) { this.impl = impl; }
    public abstract void draw();
}
