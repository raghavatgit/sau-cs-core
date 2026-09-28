package structural;

interface StreamDataSource { void write(String data); }

public class EncryptedDecorator implements StreamDataSource {
    private final StreamDataSource wrappee;
    public EncryptedDecorator(StreamDataSource s) { this.wrappee = s; }
    public void write(String data) {
        wrappee.write("[ENCRYPTED]" + data);
    }
}
