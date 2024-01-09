#ifndef TEACHER_H
#define TEACHER_H

//Incomplete, >> operator needs to be overloaded
#include "person.h"

class Teacher final : public Person 
{
    friend istream& operator>>(istream &in, Teacher &obj);
    private:
    int teacherID;
    int salary;
    Date dateJoined;

    public:
    Teacher() = default;

    Teacher(string name, string phone, string address, string dob, long long int cnic, int id, int salary, 
    string dateJoin) : Person(name, phone, address, dob, cnic), teacherID(id), salary(salary), dateJoined(dateJoin)
    {/* empty */}

    void setID (int id) {this->teacherID = id;}
    void setSalary (int salary) {this->salary = salary;}
    void setDateJoined (string &date){this->dateJoined = date;}

    int getID() const {return teacherID;}
    int getSalary() const {return salary;}
    Date getDate() const {return dateJoined;}

    void printData()
    {
        Person::printData();
        cout << "ID: " << teacherID << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date Joined: " << dateJoined << endl;
    }

    void printTabularData()
    {
        cout << "| " << left << setw(25) << getName() << "| " << setw(12) << getPhone() << "| " << 
        setw(40) << getAddress() << "| " << setw(14) << getDateOfBirth() << "| " << setw(4) << getAge()
        << "| " << setw(15) << getCNIC() << "| " << setw(3) << teacherID << "| " << 
        setw(6) << salary << "| " << setw(14) << dateJoined << "|\n";
    }

    void printTitle()
    {
        cout << "| " <<  left << setw(25) << "Name" << "| " << setw(12) << "Phone" << "| " << 
            setw(40) << "Address" << "| " << setw(14) << "Date of Birth" << "| " << setw(4) << "Age"
            << "| " << setw(15) << "CNIC" << "| " << setw(3) << "ID" << "| " << 
            setw(6) << "Salary" << "| " << setw(14) << "Date Joined" << "|\n" ;
    }

    bool operator==(const Teacher& obj)
    {
        if(teacherID == obj.getID())
        {
            return true;
        }
        return false;
    }

    bool operator==(const int& obj)
    {
        if(teacherID == obj)
        {
            return true;
        }
        return false;
    }

    bool operator<(const Teacher& obj)
    {
        if(teacherID < obj.getID())
        {
            return true;
        }
        return false;
    }

    bool operator<(const int& obj)
    {
        if(teacherID < obj)
        {
            return true;
        }
        return false;
    }
      
};


ostream& operator<<(ostream &out, const Teacher &obj)
{
    out << quoted(obj.getName()) << " " << obj.getPhone() << " " << quoted(obj.getAddress()) << " "
    << obj.getDateOfBirth().toString() << " " << obj.getCNIC() << " " << obj.getID() 
    << " " << obj.getSalary() << " " << obj.getDate() << "\n";
    return out;
}

istream& operator>>(istream &in, Teacher &obj)
{
    string n;
    long long int i;
    in >> quoted(n);
    obj.setName(n);
    in >> n;
    obj.setPhone(n);
    in >> quoted(n);
    obj.setAddress(n);
    in >> n;
    obj.setDateOfBirth(n);
    in >> i;
    obj.setCNIC(i);
    in >> obj.teacherID >> obj.salary >> obj.dateJoined;
    in.ignore();
    return in;
}


#endif