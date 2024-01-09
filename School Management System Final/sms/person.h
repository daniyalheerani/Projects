#ifndef PERSON_H
#define PERSON_H

//Completed, only operators need overloading

#include <string>
#include <iomanip>
#include "date.h"

class Person
{
    private:
    string name;
    string phone;
    string address;
    Date dateOfBirth;
    int age;
    long long int cnic;

    public:
    //generate default constructor
    Person() = default;

    Person(string name, string phone, string address, string dob, long long int cnic = 0)
    : dateOfBirth(Date(dob)), name(name), phone(phone), address(address), cnic(cnic)
    {
        age = (getCurrentDate()-dateOfBirth)/365;
    }

    void setName(string nameOfPerson) 
    {
        name = nameOfPerson;
    }
    void setAddress(string addr) 
    {
        address = addr;
    }
    
    bool setPhone(string ph) 
    {
        if(ph.size() == 11)
        {
            phone = ph;
            return true;
        }
        return false;
    }
    
    bool setCNIC(long long int nic)
    {
        if(to_string(nic).size() == 13 || nic == 0)
        {
            cnic = nic;
            return true;
        }
        return false;
    }

    void setDateOfBirth(string date)
    {
        dateOfBirth = date;
        age = (getCurrentDate()-dateOfBirth)/365;
    }

    string getName() const {return name;}
    string getAddress() const {return address;}
    long long int getCNIC() const {return cnic;}
    string getPhone() const {return phone;}
    Date getDateOfBirth() const {return dateOfBirth;}
    int getAge() const {return age;}

    void printData()
    {
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
    }
    
};

#endif
