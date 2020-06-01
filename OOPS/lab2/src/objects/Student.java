package objects;

public class Student {

    private String USN;
    private String Name;
    private Address addr;

    public Student(String USN, String name, Address addr) {
        this.USN = USN;
        Name = name;
        this.addr = addr;
    }

    @Override
    public String toString() {
        return "Student{" +
                "USN='" + USN + '\'' +
                ", Name='" + Name + '\'' +
                ", addr=" + addr +
                '}';
    }
}
