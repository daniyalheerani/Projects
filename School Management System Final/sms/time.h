#ifndef TIME_H
#define TIME_H

//Looks complete, setters need redifinition

#include <string>
#include <iomanip>
#include <sstream>
#include <regex>
#include <iostream>
#include "helper.h"
using namespace std;

// Time class definition.
class Time {
    
    friend istream& operator>>(istream&, Time &);
    private:
    unsigned int hour = 0; // 0 - 23 (24-hour clock format)
    unsigned int minute = 0; // 0 - 59

    bool isTimeFormatValid(string time)
    {
        return regex_match(time, regex("^[0-2]?\\d[:][0-5]?[0-9]$"));
    }

    public:
    //Constructor
    Time() = default;

    Time(int hr, int min)
    :hour(hr), minute(min)
    {/* empty */}

    Time(string time)
    {
        if(isTimeFormatValid(time))
        {
            istringstream iss(time);
            iss >> hour;
            iss.ignore();
            iss >> minute;
        }
        else
        {
            throw runtime_error("Invalid Time Format");
        }
    }

    //Copy Constructor
    Time(const Time &p)
    {
        hour = p.getHour();
        minute = p.getMinute();
    }

    //SETTERS
    //set hour 
    bool setHour(int hr)
    {   
        if(hr >= 0 && hr <=23)
        {
            this->hour = hr;
            return true;
        } 
        return false;
    }    

    // set minute                
    bool setMinute(int min)
    {
        if(min >= 0 && min <=59)
        {
            this->minute = min;
            return true;
        }    
        return false;
    } 

    bool setTime(int hr, int min)
    {
        return setHour(hr) && setMinute(min);
    }


    string toString() const
    {
        ostringstream oss;
        oss << setfill('0');
        oss << setw(2) << this->getHour() << ":" << setw(2) << this->getMinute();
        return oss.str();
    }                    

    //overloaded operators

    bool operator==(const Time& t)
    {
        if(this->hour == t.getHour() && this->minute == t.getMinute())
        {
            return true;
        }
        return false;
    }

    bool operator!=(const Time &t)
    {
        if(*this == t)
        {
            return false;
        }
        return true;
    }

    //get functions
    unsigned int getHour()  const { return hour;} // return hour
    unsigned int getMinute() const { return minute;} // return minute

};

istream& operator>>(istream& in, Time &obj)
{
    in >> obj.hour;
    in.ignore();
    in >> obj.minute;
    return in;
}

ostream& operator<<(ostream& out, const Time &obj)
{
    out << obj.toString();
    return out;
}


#endif