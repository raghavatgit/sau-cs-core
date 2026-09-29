package behavioral;

import java.util.Iterator;

public class CustomArrayCollection<T> implements Iterable<T> {
    private final Object[] elements;
    public CustomArrayCollection(Object[] elems) { this.elements = elems; }

    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private int index = 0;
            public boolean hasNext() { return index < elements.length; }
            @SuppressWarnings("unchecked")
            public T next() { return (T) elements[index++]; }
        };
    }
}
