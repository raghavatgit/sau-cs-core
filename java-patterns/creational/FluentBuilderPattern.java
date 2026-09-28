package creational;

public class HttpRequest {
    private final String url;
    private final String method;
    private final int timeoutMs;

    private HttpRequest(Builder builder) {
        this.url = builder.url;
        this.method = builder.method;
        this.timeoutMs = builder.timeoutMs;
    }

    public static class Builder {
        private String url;
        private String method = "GET";
        private int timeoutMs = 5000;

        public Builder url(String url) { this.url = url; return this; }
        public Builder method(String method) { this.method = method; return this; }
        public Builder timeout(int ms) { this.timeoutMs = ms; return this; }
        public HttpRequest build() { return new HttpRequest(this); }
    }
}
