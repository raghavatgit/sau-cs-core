package creational;

interface Button { void render(); }
interface Checkbox { void render(); }

class DarkButton implements Button { public void render() { System.out.println("Render Dark Button"); } }
class DarkCheckbox implements Checkbox { public void render() { System.out.println("Render Dark Checkbox"); } }

interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}

public class DarkUIFactory implements GUIFactory {
    public Button createButton() { return new DarkButton(); }
    public Checkbox createCheckbox() { return new DarkCheckbox(); }
}
