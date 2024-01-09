#ifndef CLASS_H
#define CLASS_H
//almost complete
#include "time.h"


class Class
{
    friend std::istream& operator>>(std::istream&, Class &);
    private:
    //Room, day and time from and to  will uniquely identify a Class
    int classID;
    std::string roomName;
    std::string sectionName;
    int gradeID;
    std::string day;
    Time from;
    Time to;
    int teacherID;
    std::string subid;

    public:
    Class()
    {
        classID = 0;
    }

    Class(int cid, std::string room, std::string sec, int grade, std::string day, std::string timefrom, std::string timeto,  int tid, std::string sub)
    : classID(cid), roomName(room), sectionName(sec), gradeID(grade), day(day), from(timefrom), to(timeto), subid(sub), teacherID(tid)
    {/* empty */}

    void setClassID(int id) {classID = id;}
    void setRoomName(std::string room){roomName = room;}
    void setSectionName(std::string s){sectionName = s;}
    void setGradeID(int id){gradeID = id;}
    void setDay(std::string d){day = d;}
    void setFromTime(std::string t){from = t;}
    void setToTime(std::string t){to = t;}
    void setSubID(std::string s) {subid = s;}
    void assignTeacherID(int newteacherID) {teacherID = newteacherID;}


    int getClassID() const {return classID;}
    std::string getRoomName() const {return roomName;}
    std::string getSectionName() const {return sectionName;}
    int getGradeID()const {return gradeID;}
    std::string getDay() const {return day;}
    Time getFromTime() const {return from;}
    Time getToTime() const {return to;}
    int getTeacherID() const {return teacherID;}
    std::string getSubid() const {return subid;}
    std::string getGradeAndSection() const {return to_string(gradeID)+sectionName;}
    std::string getUniqueKey() const {return roomName+day+from.toString()+to.toString();}

    bool operator==(const Class &c)
    {
        if(roomName == c.getRoomName() && day == c.getDay() && from == c.getFromTime() && to == c.getToTime())
        {
            return true;
        }
        return false;
    }

    bool operator==(const string &c)
    {
        if(roomName == c)
        {
            return true;
        }
        return false;
    }

    bool operator==(const Teacher &c)
    {
        if(teacherID == c.getID())
        {
            return true;
        }
        return false;
    }

    bool operator==(const int &c)
    {
        if(classID == c)
        {
            return true;
        }
        return false;
    }

    bool operator!=(const Class &c)
    {
        if(!(*this==c))
        {
            return true;
        }
        return false;
    }

    bool operator>(const Class &c)
    {
        if(classID > c.getClassID())
        {
            return true;
        }
        return false;
    }

    void printTitle()
    {
        cout << "| " <<  left << setw(8) << "Class ID" << "| " << setw(10) << "Room Name" << "| " << setw(6) << "Grade" << "| " << 
        setw(8) << "Section" << "| " << setw(8) << "Sub ID" << "| " << setw(10) << "Day" << "| " << 
        setw(6) << "From" << "| " << setw(6) << "To" << "| " << setw(11) << "Teacher ID" << "|\n" ;
    }


    void printTabularData()
    {
        cout << "| " <<  left << setw(8) << classID << "| "<< setw(10) << roomName << "| " << setw(6) << gradeID << "| " << 
        setw(8) << sectionName << "| " << setw(8) << subid << "| " << setw(10) << day << "| " << 
        setw(6) << from << "| " << setw(6) << to << "| " << setw(11) << teacherID << "|\n" ;
    }

    void printData()
    {
        cout << "Class ID: " << classID << endl;
        cout << "Room Name: " << roomName << endl;
        cout << "Grade: " << gradeID << endl;
        cout << "Section: " << sectionName << endl;
        cout << "Subject ID: " << subid << endl;
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Day: " << day << endl;
        cout << "From: " << from << endl;
        cout << "To: " << to << endl;
        
    }
};

std::istream& operator>>(std::istream&in, Class &obj)
{
    in >> obj.classID >> obj.roomName >> obj.sectionName >> obj.gradeID >> obj.day >> obj.from >> obj.to >> obj.teacherID >> obj.subid;
    in.ignore();
    return in;
}

std::ostream& operator<<(std::ostream&out, const Class &obj)
{
    out << obj.getClassID() << " " << obj.getRoomName() << " " << obj.getSectionName() << " " << obj.getGradeID() << " " << obj.getDay()
    << " " << obj.getFromTime() << " " << obj.getToTime() << " " << obj.getTeacherID() << " " << obj.getSubid() << "\n";
    return out;
}

std::string createClassUniqueKey(const std::string &roomName, const std::string &day, const Time &from, const Time &to)
{
    return roomName+day+from.toString()+to.toString();
}

/* Class c1("G-1", "AM", 1, "Monday", "8:00", "9:00", 1, "CS1");  */
#endif