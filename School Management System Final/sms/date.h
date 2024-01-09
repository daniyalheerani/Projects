#ifndef DATE_H
#define DATE_H

//Completed

#include <chrono>
#include <regex>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "helper.h"
using namespace std;

//Exception class
class InvalidDate : public runtime_error
{
    public:
    InvalidDate(string comment)
    :runtime_error(comment)
    {/* empty */}
};

class Date {
   friend istream& operator>>(istream&, Date&);
   private:
      unsigned int month;
      unsigned int day;
      unsigned int year;
      // days per month
      static unsigned int days[13]; 
      // utility function for incrementing date
      void helpIncrement()
      {
         // day is not end of month
         if (!endOfMonth(day)) 
         {
            ++day; // increment day
         }
         else 
         {
            if (month < 12)
            { // day is end of month and month < 12
               ++month; // increment month
               day = 1; // first day of new month
            }
            else 
            { // last day of year
               ++year; // increment year
               month = 1; // first month of new year
               day = 1; // first day of new month
            }
         }
      }
      bool isDateFormatValid(string date)
      {
         /* Checks whether the given string represents a valid date
         in format dd-mm-yyyy */
         return regex_match(date, regex("^(0[1-9]|[12][0-9]|3[01]|[1-9])[-](0[1-9]|1[012]|[1-9])[-](19|20)\\d\\d$"));
      }

   public:
      //generate default constructor
      Date() = default;

      //Construct date with 3 integer arguments
      Date(int d, int m, int y)
      {
         if(!setDate(d, m, y))
         {
            throw InvalidDate("Invalid Date");
         }
      }

      //Cast a string of format dd-mm-yyyy to Date object or create a date using string
      Date(string date)
      {
         int d, m , y;
         if(isDateFormatValid(date))
         {
            istringstream iss(date);
            iss >> d;
            iss.ignore();
            iss >> m;
            iss.ignore();
            iss >> y;
            if(!setDate(d, m, y))
            {
               throw InvalidDate("Invalid Date");
            }
         }
         else
         {
            throw InvalidDate("Invalid Format");
         }
      }
      //Copy constructor
      Date(const Date &d)
      {
         this->day = d.getDay();
         this->month = d.getMonth();
         this->year = d.getyear();
      }

      ~Date() = default;

      // set month, day, year
      bool setDate(int d, int m, int y)
      {
         bool valid = false;
         if(y > 1899 && y < 2100)
         {
            if(m > 0 && m < 13)
            {
               if(m == 2 && leapYear(y))
               {
                  if(d > 0 && d < 30)
                  {
                     valid = true;
                  }
               }
               else
               {
                  if(d > 0 && d <= days[m])
                  {
                     valid = true;
                  }
               }
            }
         }
         day = d;
         month = m;
         year = y;
         return valid;
      }

      int getyear() const {return year;}
      int getDay() const {return day;}
      int getMonth() const {return month;}

      // prefix increment operator
      Date& operator++()
      {
         helpIncrement(); // increment date                   
         return *this; // reference return to create an lvalue
      }

      // add days                  
      Date& operator+=(unsigned int additionalDays)
      {
         for (unsigned int i = 0; i < additionalDays; ++i) 
         {
            helpIncrement();
         }
         return *this; // enables cascading                      
      }

      bool operator==(const Date &d)
      {
         if(this->day==d.getDay() && this->month == d.getMonth() && this->year == d.getyear())
         {
            return true;
         }
         return false;
      }

      bool operator>(const Date &d)
      {
         if(this->year>d.getyear())
         {
            return true;
         }
         else if(this->year==d.getyear())
         {
            if(this->month>d.getMonth())
            {
               return true;
            }
            else if(this->month == d.getMonth())
            {
               if(this->day > d.getDay())
               {
                  return true;
               }
            }
         }
         return false;
      }

      bool operator<(const Date &d)
      {
         if(!(*this==d) && !(*this>d))
         {
            return true;
         }
         return false;
      }

      int operator-(Date d)
      {
         int diff = 0;
         if(*this>d)
         {
            while(!(*this==d))
            {
               ++d;
               ++diff;
            }
         }
         else
         {
            while(!(*this==d))
            {
               ++(*this);
               --diff;
            }
         }
         return diff;
      }

      // is year a leap year?
      static bool leapYear(int testYear)
      {
         return (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0));
      }
      
      // is day at the end of month?
      bool endOfMonth(int testDay) const
      {
         if (month == 2 && leapYear(year)) 
         {
            return testDay == 29; // last day of Feb. in leap year
         }
         else 
         {
            return testDay == days[month];
         }
      }

      string toString() const
      {
         ostringstream oss;
         oss << setfill('0');
         oss << setw(2) << this->day << "-" << setw(2) << this->month << "-" << this->year;
         return oss.str();
      }

};

// initialize static member; one classwide copy
unsigned int Date::days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


// overloaded output operator
ostream& operator<<(ostream& output, const Date& d) {
   output << d.toString();
   return output; // enables cascading
}

istream& operator>>(istream& in, Date& d)
{
   string date;
   in >> date;
   d = date;
   return in;
}

Date getCurrentDate() 
{
   time_t  t = chrono::system_clock::to_time_t(chrono::system_clock::now());
   tm *t2;
   t2 = localtime(&t);
   return Date(int(t2->tm_mday), int(t2->tm_mon)+1, int(t2->tm_year)+1900);
}

#endif
