#ifndef TEACHERMANAGEMENT_H
#define TEACHERMANAGEMENT_H

#include <iostream>
#include "management.h"


using namespace std;

class TeacherManagement : public Management
{
    private:
    //Sub Operations of Operation 1-> Search Teacher by ID
    int showSubOperations()
    {
        int option;
        cout << "\n1-> Edit Information\n";
 //       cout << "2-> View Classes Schedule\n";
        cout << "3-> Delete\n";
        cout << "4-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 4, "? ", "Invalid Option Selected, Please try Again\n");
        return option;
    }

    void changeTeacher(Teacher &object, bool changeAll, int option = 0)
    {
        //object : A Teacher object to change
        //Option : which attribute to change?
        //changeAll : a bool, if true changes all attributes
        if(!Management::changePerson(object, changeAll, option) || changeAll)
        {
            //6-> Edit Salary
            if(option == 6 || changeAll)
            {
                int salary = get_int("Enter salary: ");
                object.setSalary(salary);
                if(!changeAll){return;}
            }

            //7-> Edit Date Joined
            if(option == 7 || changeAll)
            {
                string dateJoined;
                while(true)
                {
                    dateJoined = get_string("Enter Date Joined in Format dd-mm-yyyy: ");
                    try
                    {
                        object.setDateJoined(dateJoined);
                        if(object.getDate() < getCurrentDate())
                        {
                            break;
                        }
                        else
                        {
                            cout << "Current date is: " << getCurrentDate() << endl;
                        }
                        break;
                    }
                    catch (const InvalidDate& invdate)
                    {
                        cout << invdate.what() << endl;
                    }
                }
                if(!changeAll){return;}
            }
        }
    }

    //3-> Add a Teacher
    void addTeacher()
    {
        system("cls");
        Teacher toAdd;
        changeTeacher(toAdd, true);
        toAdd.setID(teachers.getMax()->data.getID()+1);
        teachers.insert(toAdd);
        cout << "Teacher Added Successfully!\nPress any key to go back";
        getch();
    }


    //1-> Edit Information
    void editInformation(Teacher &object)
    {
        system("cls");
        int option;
        cout << "1-> Edit Name\n";
        cout << "2-> Edit Phone\n";
        cout << "3-> Edit Address\n";
        cout << "4-> Edit Date of Birth\n";
        cout << "5-> Edit CNIC\n";
        cout << "6-> Edit Salary\n";
        cout << "7-> Edit Date Joined\n";
        cout << "8-> Back\n";
        option = get_int_in_range(1, 8, "? ", "Invalid Option Selected, Please try Again\n");

        if (option != 8)
        {
            system("cls");
            changeTeacher(object, false, option);
            system("cls");
        }
    }

    //2-> View Classes Schedule
    /* void viewClassesSchedule(Teacher &object)
    {
        system("cls");
        cout << object.getName() << "'s Schedule:\n";
        Management::viewEntries("class.txt", &Class::printTabularData, "Teacher has not been assigned any subject yet",
        object.getID(), true, true, &Class::getTeacherID);
    } */

    //3-> Delete
    bool deleteTeacher(Teacher &object)
    {
        char c = get_specific_chars("yn", "\n\nAre you sure you want to delete this teacher (y/n)? ");
        if(c == 'y')
        {
            //Delete the teacher 
            teachers.deleteNode(object);
            cout << "Teacher Deleted successfully\nPress any key to go back";
            getch();
            return true;
        }
        return false;
    }

    public:
    
    int showOperations() override
    {
        int option;
        cout << "1-> Search Teacher by ID\n";
        cout << "2-> View All Teachers\n";
        cout << "3-> Add a Teacher\n";
        cout << "4-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 4, "? ", "Invalid Option Selected, Please try Again\n");
            
        return option;
        
    }

    int performOperation(int option) override
    {
        switch(option)
        {
            //1-> Search Teacher by ID
            case 1:
            {
                int id = get_int("Enter Teacher's ID: ");
                Teacher obj;
                obj.setID(id);
                Node<Teacher>* found = teachers.search(obj);
                while(found != nullptr)
                {
                    obj = found->data;
                    system("cls");
                    obj.printData();
                    int option2 = showSubOperations();
                    if(option2 != 0 && option2 != 4)
                    {
                        switch(option2)
                        {
                            //1-> Edit Information
                            case 1:
                            editInformation(obj);
                            found->data = obj;
                            break;

                            //2-> View Classes Schedule
                            case 2:
                            //viewClassesSchedule(obj);
                            break;

                            //3 Delete
                            case 3:
                            {
                                if(deleteTeacher(obj))
                                {
                                    return option2;
                                }
                                break;
                            }
                            
                        } 
                    }
                    else
                    {
                        return option2;
                    }
                }
                if(found == nullptr)
                {
                    cout << "Teacher not found\nPress any key to go back\n";
                    getch();
                }
                break;
                
            }
            //2-> View All Teachers
            case 2:
            {   
                if(!teachers.isEmpty())
                {
                    int i = 0;
                    teachers.display(i, Teacher::printTitle, Teacher::printTabularData, false);
                }
                else
                {
                    cout << "No Teachers have been added";
                    
                }
                cout << "\nPress any key to go back";
                getch();
                
            }
            break;

            case 3:
            addTeacher();
            break;
        }
        return option;
    }

    string showManagementType() override { return "teachermanagement"; }

    int getNumberOfOperations() override { return 3; }
};

#endif