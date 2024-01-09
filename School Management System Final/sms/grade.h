#ifndef GRADE_H
#define GRADE_H

//incomplete, operators need to be overloaded

#include <string>
#include <iostream>


class Grade
{
    friend std::istream& operator >>(std::istream &, Grade &);
    private:
    int gradeID;
    std::string gradeName;
    int totalSubjects;

    public:
    Grade() = default;
    Grade(int id, std::string gradeName, int totalSubs)
    : gradeID(id), gradeName(gradeName), totalSubjects(totalSubs)
    {/* empty */}


    int getGradeID()const {return gradeID;}
    std::string getGradeName() const {return gradeName;}
    int getTotalSubjects() const {return totalSubjects;}

    void setGradeID(int id) {gradeID = id;}
    void setGradeName(std::string name) {gradeName = name;}
    void setTotalSubjects(int total) {totalSubjects = total;}

    bool operator==(const Grade &g)
    {
        if(gradeID == g.getGradeID())
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
        cout << "| " <<  left << setw(9) << "Grade ID" << "| " << setw(11) << "Grade Name" << "| " << 
        setw(14) << "Total Subjects" << "|\n" ;
    }

    void printTabularData()
    {
        cout << "| " <<  left << setw(9) << gradeID << "| " << setw(11) << gradeName << "| " << 
        setw(14) << totalSubjects << "|\n" ;
    }
};

std::ostream& operator<<(std::ostream &out, const Grade &obj)
{
    out << obj.getGradeID() << " " << obj.getGradeName() <<  " " << obj.getTotalSubjects() << "\n";
    return out;
}

std::istream& operator>>(std::istream &in, Grade &obj)
{
    in >> obj.gradeID >> obj.gradeName >> obj.totalSubjects;
    in.ignore();
    return in;
}
//When opening the program for first time, these will exist initially
/* Grade g1(1, "First", 5);
Grade g2(2, "Second", 5); */
#endif