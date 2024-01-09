#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <iostream>
#include "management.h"



using namespace std;

class StudentManagement : public Management
{
    private:

    int showSubOperations()
    {
        int option;
        cout << "\n1-> Edit Information\n";
        cout << "2-> Delete\n";
        cout << "3-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 3, "? ", "Invalid Option Selected, Please try Again\n");
        return option;
    }

    void changeStudent(Student &object, bool changeAll, int option = 0)
    {
        //object : A Student object to change
        //Option : which attribute to change?
        //changeAll : a bool, if true changes all attributes, used to add a student
        if(!Management::changePerson(object, changeAll, option) || changeAll)
        {
            //6-> Edit Admission Date
            if(option == 6 || changeAll)
            {
                string admissionDate;
                while(true)
                {
                    admissionDate = get_string("Enter Admission Date in Format dd-mm-yyyy: ");
                    try
                    {
                        object.setAdmissionDate(admissionDate);
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
                if(!changeAll){return;}
            }

            //7-> Add Grade
            if(changeAll)
            {
                int grade; 
                do
                {
                    Grade temp;
                    grade = get_int_in_range(1, 10, "Enter Grade 1-10: ");
                    temp.setGradeID(grade);
                    if(grades.search(temp) != nullptr)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Grade " << grade << " does not exist, Please try again\n";
                    }
                } 
                while(true);
                object.setStudentGrade(grade);
                if(!changeAll){return;}
            }

            //8-> Add Section
            if(changeAll)
            {
                string section;
                while(true)
                {
                    section = get_string("Enter Section Name: ");
                    upperString(section);
                    string gradeAndSection = to_string(object.getStudentGrade())+section;
                    if(sections.search(gradeAndSection) != nullptr)
                    {
                        Section temp;
                        temp.setGradeID(object.getStudentGrade());
                        temp.setName(section);
                        node<Section>* sect = sections.search(temp);
                        temp = sect->data;
                        if(temp.isSectionFull())
                        {
                            cout << "Section " << section << "of Grade " << object.getStudentGrade()<< " is Full, Please try in different section\n";
                        }
                        else
                        {
                            //increase current student in section
                            ++sect->data;
                            break;
                        }
                    }
                    else
                    {
                        cout << "Invalid, " << "Section " << section << "of Grade " << object.getStudentGrade()<< " does not exist, Please try Again\n";
                    }
                }
                object.setStudentSection(section);
                if(!changeAll){return;}
            }
        }
    }

    void addStudent()
    {
        system("cls");
        Student toAdd;
        changeStudent(toAdd, true);
        toAdd.setstudentID(students.getMax()->data.getstudentID()+1);
        students.insert(toAdd);
        cout << "Student Added Successfully!\nPress any key to go back";
        getch();
    }

    void viewStudentsByGradeAndSection()
    {
        int gradeID = get_int("Enter Grade ID: ");
        if(grades.search(gradeID))
        {
            string sectionName = get_string("Enter section name: ");
            upperString(sectionName);
            string gradeAndSection = to_string(gradeID)+sectionName;
            if(sections.search(gradeAndSection) != nullptr)
            {
                students.display(gradeAndSection, Student::printTitle, Student::printTabularData);
                cout << "\nPress any key to go back";
                
            }
            else
            {
                cout << "Section " << sectionName << " does not exist\nPress any key to go back";
            }            
        }
        else
        {
            cout << "Grade " << gradeID << " does not exist\nPress any key to go back";
        }
        getch();
    }

    void editInformation(Student &object)
    {
        system("cls");
        int option;
        cout << "1-> Edit Name\n";
        cout << "2-> Edit Phone\n";
        cout << "3-> Edit Address\n";
        cout << "4-> Edit Date of Birth\n";
        cout << "5-> Edit CNIC\n";
        cout << "6-> Edit Admission Date\n";
        cout << "7-> Back\n";
        option = get_int_in_range(1, 7, "? ", "Invalid Option Selected, Please try Again\n");

        if (option != 7)
        {
            system("cls");
            changeStudent(object, false, option);  
        }
    }


    bool deleteStudent(Student &object)
    {
        char c = get_specific_chars("yn", "\n\nAre you sure you want to delete this student (y/n)? ");
        if(c == 'y')
        {
            Section temp;
            temp.setGradeID(object.getStudentGrade());
            temp.setName(object.getStudentSection());
            //decrease number of students in section
            --sections.search(temp)->data;
            students.deleteNode(object);
            return true;
        }
        return false;
    }

    public:

    int showOperations() override
    {
        int option;
        cout << "1-> Search Student by ID\n";
        cout << "2-> Add a Student\n";
        cout << "3-> View Students by Grade and Section\n";
        cout << "4-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 4, "? ", "Invalid Option Selected, Please try Again\n");
            
        return option;
    }

    int performOperation(int option) override
    {
        switch(option)
        {
            //1-> Search Student by ID
            case 1:
            {
                int roll = get_int_in_range(0,INT32_MAX ,"Enter Student ID: ");
                Student obj;
                obj.setstudentID(roll);
                Node<Student> * found = students.search(obj);
                while(found != nullptr)
                {
                    obj = found->data;
                    system("cls");
                    obj.printData();
                    int option2 = showSubOperations();
                    if(option2 != 0 && option2 != 3)
                    {
                        switch(option2)
                        {
                            //1-> Edit Information
                            case 1:
                            editInformation(obj);
                            found->data = obj;
                            break;

                            //2 Delete student
                            case 2:
                            {
                                if(deleteStudent(obj))
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
                    cout << "Student not found\nPress any key to go back\n";
                    getch();
                }
                break;
                
            }

            //2-> Add a Student
            case 2:
            addStudent();
            break;

            //3-> View Students By Grade and Section
            case 3:
            viewStudentsByGradeAndSection();
            break;
        }
        return option;
    }

    string showManagementType() override { return "studentmanagement"; }

    int getNumberOfOperations() override { return 3; }
};

#endif