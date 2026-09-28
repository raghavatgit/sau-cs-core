package structural;

interface JsonParser { void parseJson(String json); }

class LegacyXmlEngine {
    void processXml(String xml) { System.out.println("Processing: " + xml); }
}

public class XmlToJsonAdapter implements JsonParser {
    private final LegacyXmlEngine xmlEngine;

    public XmlToJsonAdapter(LegacyXmlEngine engine) { this.xmlEngine = engine; }

    public void parseJson(String json) {
        String convertedXml = "<json>" + json + "</json>";
        xmlEngine.processXml(convertedXml);
    }
}
