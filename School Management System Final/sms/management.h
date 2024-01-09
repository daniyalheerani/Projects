#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <string>
#include <conio.h>
#include "singlylist.h"
#include "tree.h"
#include "student.h"
#include "teacher.h"
#include "grade.h"
#include "section.h"
#include "subject.h"
#include "room.h"
#include "class.h"

extern avl <Student> students;
extern avl <Teacher> teachers;
extern list <Grade> grades;
extern list <Section> sections;
extern list <Subject> subjects;
extern list <Room> rooms;
extern list <Class> classes;


//Abstract Class Management
class Management
{
    protected:

    //Used to set person Details according to the option
    bool changePerson(Person &object, bool changeAll, int option = 0)
    {
        //object : A Person object to change
        //Option : which attribute to change?
        //changeAll : a bool, if true changes all attributes

        //1-> Add/Edit Name
        if(option == 1 || changeAll)
        {
            string name = get_string("Enter name: ");
            object.setName(name);
            if(!changeAll){return true;} 
        }

        //2-> Add/Edit Phone
        if(option == 2 || changeAll)
        {
            string phone = get_digits(11, "Enter 11 Digits Phone# without dashes and (+/-): "
            , "Invalid Phone number, Please try again\n");
            object.setPhone(phone);
            if(!changeAll){return true;}
        }

        //3-> Add/Edit Address
        if(option == 3 || changeAll)
        {
            string address = get_string("Enter address: ");
            object.setAddress(address);
            if(!changeAll){return true;}
        }

        //4-> Add/Edit Date of Birth
        if(option == 4 || changeAll)
        {
            string dateOfBirth;
            while(true)
            {
                dateOfBirth = get_string("Enter Date of Birth in Format dd-mm-yyyy: ");
                try
                {
                    object.setDateOfBirth(dateOfBirth);
                    if(object.getDateOfBirth() < getCurrentDate())
                    {
                        break;
                    }
                    else
                    {
                        cout << "Current date is: " << getCurrentDate() << endl;
                    }
                }
                catch (const InvalidDate& invdate)
                {
                    cout << invdate.what() << endl;
                }
            }
            if(!changeAll){return true;}
        }

        //5-> Add/Edit CNIC
        if(option == 5 || changeAll)
        {
            long long int cnic = stoll(get_digits(13, "Enter 13 digits CNIC Number without dashes or 0: "
            , "Invalid CNIC, Please try again\n"));
            object.setCNIC(cnic);
            if(!changeAll){return true;}
        }
        return changeAll;
    }

    public:
    virtual int showOperations() = 0;

    virtual std::string showManagementType() = 0;

    virtual int performOperation(int option) = 0;
    //useful to implement the back operation
    virtual int getNumberOfOperations() = 0;

    //virtual destructor
    virtual ~Management()
    {

    }
    
};

#endif