package objects;

public class Employee {

    private String EmpID;
    private String Name;
    private Address addr;

    @Override
    public String toString() {
        return "Employee{" +
                "EmpID='" + EmpID + '\'' +
                ", Name='" + Name + '\'' +
                ", addr=" + addr +
                '}';
    }

    public Employee(String EmpID, String name, Address addr) {
        this.EmpID = EmpID;
        Name = name;
        this.addr = addr;
    }

}
