package objects;

public class College {

    private String Name;
    private Address addr;

    public College( String name, Address addr) {
        Name = name;
        this.addr = addr;
    }

    @Override
    public String toString() {
        return "College{" +
                "Name='" + Name + '\'' +
                ", addr=" + addr +
                '}';
    }
}
