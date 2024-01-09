#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <iostream>

//incomplete, some operators need to be overloaded
class Subject
{
    friend std::istream& operator>>(std::istream&, Subject &);
    private:
    std::string subID;
    std::string subName;
    int gradeID;

    public:
    Subject() = default;
    Subject(std::string id, std::string name, int gradeid)
    :subID(id), subName(name), gradeID(gradeid)
    {/* empty */}

    std::string getSubID(void) const {return subID;}
    std::string getSubName(void) const {return subName;}
    int getGradeID(void) const {return gradeID;}

    void setSubID(std::string id) {subID = id;}
    void setSubName(std::string name) {subName = name;}
    void setGradeID(int id) {gradeID = id;}

    bool operator==(const Subject &s)
    {
        if(subID == s.getSubID())
        {
            return true;
        }
        return false;
    }

    bool operator==(const Grade &g)
    {
        if(gradeID == g.getGradeID())
        {
            return true;
        }
        return false;
    }

    bool operator==(const string &s)
    {
        if(s==subID)
        {
            return true;
        }
        return false;
    }

    bool operator==(const int &g)
    {
        if(gradeID == g)
        {
            return true;
        }
        return false;
    }

    void printTitle()
    {
        cout << "| " <<  left  << setw(11) << "Subject ID" << "| " 
        << setw(20)  << "Subject Name" << "| " << setw(6) << "Grade" << "|\n" ;
    }

    void printTabularData()
    {
        
        cout << "| " <<  left  << setw(11) << subID << "| " 
        << setw(20)  << subName << "| " << setw(6) << gradeID << "|\n" ;
    }
};

std::istream& operator>>(std::istream &in, Subject &obj)
{
    in >> obj.subID >> obj.subName >> obj.gradeID;
    in.ignore();
    return in;
}

std::ostream& operator<<(std::ostream &out, const Subject &obj)
{
    out << obj.getSubID() << " " << obj.getSubName() << " " << obj.getGradeID() << "\n";
    return out;
}

//When opening the program for first time, these will exist initially
/* Subject eng1("ENG1", "English-I", 1);
Subject eng2("ENG2", "English-II", 2);
Subject maths1("MT1", "Mathematics-I", 1);
Subject maths2("MT2", "Mathematics-II", 2);
Subject urdu1("U1", "URDU-I", 1);
Subject urdu2("U2", "URDU-1I", 2);
Subject sci1("SCI1", "SCIENCE-I", 1);
Subject sci2("SCI2", "SCIENCE-1I", 2);
Subject comp1("CS1", "ITC-I", 1);
Subject comp2("CS2", "ITC-1I", 2); */

#endif