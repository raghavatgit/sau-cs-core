package structural;

import java.util.ArrayList;
import java.util.List;

interface FileSystemComponent { void display(String indent); }

public class Directory implements FileSystemComponent {
    private final String name;
    private final List<FileSystemComponent> children = new ArrayList<>();

    public Directory(String name) { this.name = name; }
    public void add(FileSystemComponent c) { children.add(c); }

    public void display(String indent) {
        System.out.println(indent + "+ " + name);
        for (FileSystemComponent child : children) child.display(indent + "  ");
    }
}
