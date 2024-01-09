#include <fstream>
#include "studentmanagement.h"
#include "teachermanagement.h"
#include "gradesectionmanagement.h"
#include "roommanagement.h"

using namespace std;

avl <Student> students;
avl <Teacher> teachers;
list <Grade> grades;
list <Section> sections;
list <Subject> subjects;
list <Room> rooms;
list <Class> classes;

string filenames[7] = {"student.txt", "teacher.txt", "grade.txt", "section.txt", "subject.txt", "room.txt", "class.txt"};
Management *managementType;

void saveData();
void loadData();
void setManagementType(int);
int showMainMenu();

int main()
{
    //makes sure that all filenames are there
    loadData();
   
    managementType = nullptr;

    int option;
    do
    {
        //show the Main Menu
        option = showMainMenu();
        if(option != 0)
        {
            do
            {
                //Show the operations that user can perform
                system("cls");
                option = managementType->showOperations();
                if(option != 0 && option != (managementType->getNumberOfOperations()+1))
                {
                    system("cls");
                    //perform the Selected Operations
                    option = managementType->performOperation(option);
                }
                else
                {
                    break;
                }
            }
            while(option != 0);
        }
        else
        {
            break;
        }
    }
    while(option != 0);

    if(managementType != nullptr)
    {
        delete managementType;
    }

    //save Changes to file
    saveData();
}



void saveData()
{
    //loads data from filenames to memory if load is true else saves data
    
    for(int i = 0; i < 7; i++)
    {
        fstream file(filenames[i], ios::out);
        
        if(file.good())
        {
            switch(i)
            {
                case 0:
                students.outputTo(file);
                break; 
                
                case 1:
                teachers.outputTo(file); 
                break;

                case 2:
                grades.outputToFile(filenames[i]);
                break;

                case 3:
                sections.outputToFile(filenames[i]);
                break;

                case 4:
                subjects.outputToFile(filenames[i]);
                break;

                case 5:
                rooms.outputToFile(filenames[i]);
                break;

                case 6:
                classes.outputToFile(filenames[i]);
                break;
            }
        }
        file.close();
    }
    
}

void loadData()
{
    for(int i = 0; i < 7; i++)
    {
        fstream file(filenames[i], ios::in);
        if(file.good())
        {
            switch(i)
            {
                case 0:
                {
                    while(file.peek() != EOF)
                    { 
                        Student temp;
                        file >> temp;
                        students.insert(temp);
                    }
                    break; 
                }

                case 1:
                {
                    while(file.peek() != EOF)
                    { 
                        Teacher temp;
                        file >> temp;
                        teachers.insert(temp);
                    }
                    break;
                }

                case 2:
                {
                    while(file.peek() != EOF)
                    { 
                        Grade temp;
                        file >> temp;
                        grades.insertAtEnd(temp);
                    }
                    break;
                }

                case 3:
                {
                    while(file.peek() != EOF)
                    { 
                        Section temp;
                        file >> temp;
                        sections.insertAtEnd(temp);
                    }
                    break;
                }

                case 4:
                {
                    while(file.peek() != EOF)
                    { 
                        Subject temp;
                        file >> temp;
                        subjects.insertAtEnd(temp);
                    }
                    break;
                }

                case 5:
                {
                    while(file.peek() != EOF)
                    { 
                        Room temp;
                        file >> temp;
                        rooms.insertAtEnd(temp);
                    }
                    break;
                }

                case 6:
                {
                    while(file.peek() != EOF)
                    { 
                        Class temp;
                        file >> temp;
                        classes.insertAtEnd(temp);
                    }
                    break;
                }
            }
        }
        file.close();
    }
}

void setManagementType(int option)
{
    //set management Pointer according to the option selected by User
    if(managementType != nullptr)
    {
        delete managementType;
        managementType = nullptr;
    }

    switch(option)
    {
        case 1:
        managementType = new StudentManagement;
        break;

        case 2:
        managementType = new TeacherManagement;
        break;

        case 3:
        managementType = new GradeAndSectionManagement;
        break;

        case 4:
        managementType = new ClassAndRoomManagement;
        break;

    }
}

int showMainMenu()
{
    //THIS IS THE MAIN MENU OF MY PROGRAM
    system("cls");
    int option;
    cout << "1-> Student Management\n";
    cout << "2-> Teacher Management\n";
    cout << "3-> Grades and Section Management\n";
    cout << "4-> Classes and Rooms management\n";
    cout << "0-> Quit\n";
    option = get_int_in_range(0, 4, "? ", "Invalid Option Selected, Please try Again\n");
    setManagementType(option);
    return option;
}

