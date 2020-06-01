package objects;

public class Address {
    private String streetNo;
    private String City;
    private String State;
    private String Pincode;
    private String Country;
//    private String streetNo;


    public Address(String streetNo, String city, String state, String pincode, String country) {
        this.streetNo = streetNo;
        City = city;
        State = state;
        Pincode = pincode;
        Country = country;
    }

    @Override
    public String toString() {
        return "Address{" +
                "streetNo='" + streetNo + '\'' +
                ", City='" + City + '\'' +
                ", State='" + State + '\'' +
                ", Pincode='" + Pincode + '\'' +
                ", Country='" + Country + '\'' +
                '}';
    }
}
