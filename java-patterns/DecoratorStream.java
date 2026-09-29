package org.sau.patterns;

public class DecoratorStream {
    public interface Component {
        String process(String input);
    }

    public static class BaseComponent implements Component {
        public String process(String input) { return input; }
    }

    public static class TimestampDecorator implements Component {
        private final Component wrapped;
        public TimestampDecorator(Component wrapped) { this.wrapped = wrapped; }
        public String process(String input) {
            return "[" + System.currentTimeMillis() + "] " + wrapped.process(input);
        }
    }
}
