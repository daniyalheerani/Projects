#ifndef SECTION_H
#define SECTION_H

//Incomplete..
#include <string>
#include <iostream>

class Section
{
    friend std::istream& operator>>(std::istream &, Section &);
    private:
    std::string name;
    int gradeID;
    int maxStudents;
    int currentStudentsCount;

    public:
    Section() = default;
    Section(std::string name, int id, int ts = 20, int cs = 0)
    : name(name), gradeID(id), maxStudents(ts), currentStudentsCount(cs)
    {/* empty */}

    int getMaxStudents() const {return maxStudents;}
    int getCurrentStudentsCount() const {return currentStudentsCount;}
    std::string getName() const {return name;}
    int getGradeID() const {return gradeID;}
    std::string getGradeAndSection() const {return to_string(gradeID)+name;}

    void setName(std::string n) {name = n;}
    void setGradeID(int i) {gradeID = i;}
    void setMaxStudents(int size) {maxStudents = size;}
    void setCurrentStudents(int i) {currentStudentsCount = i;}
    bool isSectionFull()
    {
        if(currentStudentsCount == maxStudents)
        {
            return true;
        }
        return false;
    }

    int operator++(){++currentStudentsCount; return currentStudentsCount;}
    int operator--(){--currentStudentsCount; return currentStudentsCount;}
    bool operator==(const Section &s)
    {
        if(gradeID == s.getGradeID() && name == s.getName())
        {
            return true;
        }
        return false;
    }
    bool operator==(const int &s)
    {
        if(gradeID == s)
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

    bool operator==(const string s)
    {
        if(s==getGradeAndSection())
        {
            return true;
        }
        return false;
    }




    void printTitle()
    {
        cout << "| " <<  left  << setw(6) << "Grade" << "| " << setw(8) << "Section" << "| " 
        << setw(15) << "Students count" << "| " << setw(14) << "Total Capacity" << "|\n" ;
    }

    void printTabularData()
    {
        cout << "| " <<  left  << setw(6) << gradeID << "| " << setw(8) << name << "| " 
        << setw(15) << currentStudentsCount << "| " << setw(14) << maxStudents << "|\n" ;
    }

};

std::istream& operator>>(std::istream &in, Section &obj)
{
    in >> obj.name >> obj.gradeID >> obj.maxStudents >> obj.currentStudentsCount;
    in.ignore();
    return in;
}

std::ostream& operator<<(std::ostream&out, const Section &obj)
{
    out << obj.getName() << " " << obj.getGradeID() << " " << obj.getMaxStudents() << " " 
    << obj.getCurrentStudentsCount() << "\n";
    return out;
}

//When opening the program for first time, these will exist initially
/* Section s1("AM", 1, 20, 3);
Section s2("BM", 1, 20, 3);
Section s3("AM", 2, 20, 3);
Section s4("BM", 2, 20, 3); */


#endif