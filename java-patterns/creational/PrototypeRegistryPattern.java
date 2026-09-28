package creational;

import java.util.HashMap;
import java.util.Map;

interface Prototype<T> { T clone(); }

class DocumentPrototype implements Prototype<DocumentPrototype> {
    private String content;
    public DocumentPrototype(String c) { this.content = c; }
    public DocumentPrototype clone() { return new DocumentPrototype(this.content); }
}
