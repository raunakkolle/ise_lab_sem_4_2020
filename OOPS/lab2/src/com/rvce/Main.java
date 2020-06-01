package com.rvce;

import objects.Address;
import objects.College;
import objects.Employee;
import objects.Student;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Address addr  =  new Address("11/24","Bagalore", "KA", "560059","INDIA" );

        Student Bhangi = new Student("1RV18IS007","Ankit", addr);
        Student Somani = new Student("1RV18IS030","Piyush", addr);

        College RVCE = new College("RV", addr);
        Employee AnishaMaam = new Employee("#NO1", "Anisha BS", addr);

        System.out.println(Bhangi);
        System.out.println(Somani);
        System.out.println(RVCE);
        System.out.println(AnishaMaam);

    }
}
