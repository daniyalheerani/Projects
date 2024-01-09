#ifndef STUDENT_H
#define STUDENT_H

//Incomplete..

#include "person.h"
#include "grade.h"


class Student final: public Person
{
    friend istream& operator>>(istream &, Student &);
    private:
    int studentID;
    Date admissionDate;
    string section;
    int grade;
    
    public:
    Student() = default;
    Student(string name, string phone, string address, string dob, int roll, string dateAdmission, string sName, int gID,
    long long int cnic = 0) 
    : Person(name, phone, address, dob, cnic), admissionDate(dateAdmission), studentID(roll), section(sName)
    , grade(gID)
    {/* Empty */}
    
    Date getAdmissionDate() const {return admissionDate;}
    int getstudentID() const {return studentID;}
    string getStudentSection() const {return this->section;}
    int getStudentGrade() const {return this->grade;}
    string getStudentGradeAndSection() const {return to_string(grade)+section;}

    void setStudentSection(string section) {this->section = section;}
    void setAdmissionDate(string date) {admissionDate = date;}
    void setStudentGrade(int grade) {this->grade = grade;}
    void setstudentID(int roll) {this->studentID = roll;}


    bool operator==(const Student& stud)
    {
        if(studentID == stud.getstudentID())
        {
            return true;
        }
        return false;
    }

    bool operator==(const Grade &g)
    {
        if(grade == g.getGradeID())
        {
            return true;
        }
        return false;
    }

    bool operator<(const Student& stud)
    {
        if(studentID < stud.getstudentID())
        {
            return true;
        }
        return false;
    }

    bool operator==(const string &s)
    {
        if(to_string(grade)+section == s)
        {
            return true;
        }
        return false;
    }

    void printData()
    {
        Person::printData();
        cout << "Student ID: " << studentID << endl;
        cout << "Admission Date: " << admissionDate << endl;
        cout << "Grade: " << grade << endl;
        cout << "Section: " << section << endl;
        
    }

    void printTitle()
    {
        cout << "| " <<  left << setw(25) << "Name" << "| " << setw(12) << "Phone" << "| " << 
        setw(40) << "Address" << "| " << setw(14) << "Date of Birth" << "| " << setw(4) << "Age"
        << "| " << setw(15) << "CNIC" << "| " << setw(7) << "STD ID" << "| " << setw(15) 
        << "Admission Date" << "| " << setw(6) << "Grade" << "| " << setw(8) << "Section " << "|\n" ;
    }

    void printTabularData()
    {
        
        cout << "| " << left << setw(25) << getName() << "| " << setw(12) << getPhone() << "| " << 
        setw(40) << getAddress() << "| " << setw(14) << getDateOfBirth() << "| " << setw(4) << getAge()
        << "| " << setw(15) << getCNIC() << "| " << setw(7) << studentID << "| " << 
        setw(15) << admissionDate << "| " << setw(6) << grade << "| " << setw(8) << section << "|\n";
    }

};

ostream& operator<<(ostream &out, const Student &obj)
{
    out << quoted(obj.getName()) << " " << obj.getPhone() << " " << quoted(obj.getAddress()) << " "
    << obj.getDateOfBirth().toString() << " " <<  obj.getstudentID() << " " << obj.getAdmissionDate().toString() 
    << " " << obj.getStudentSection() << " " << obj.getStudentGrade() << " " << obj.getCNIC() << "\n";
    return out;
}

istream& operator>>(istream &in, Student &obj)
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
    in >> obj.studentID >> obj.admissionDate >> obj.section >> obj.grade;
    in >> i;
    obj.setCNIC(i);
    in.ignore();
    return in;
}

#endif