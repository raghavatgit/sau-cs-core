package behavioral;

public abstract class AbstractEtlPipeline {
    public final void execute() {
        extract();
        transform();
        load();
    }
    protected abstract void extract();
    protected abstract void transform();
    protected abstract void load();
}
