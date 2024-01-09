#ifndef GRADESECTIONMANAGEMENT_H
#define GRADESECTIONMANAGEMENT_H

#include <iostream>
#include "management.h"

//INCOMPLETEEEE

using namespace std;

class GradeAndSectionManagement : public Management
{
    private:

    void viewSections()
    {
        int grade = get_int("Enter Grade: ");
        if(grades.search(grade) != nullptr)
        {
            system("cls");
            cout << "Sections of Grade " << grade  << ":" << endl;
            int count = sections.displaySpecific(grade, Section::printTitle, Section::printTabularData);
            if(count == 0)
            {
                cout << "There are no sections for this grade\n";
            }
            cout << "Press any key to go back\n";
            getch();
            
        }
        else
        {
            cout << "Grade " << grade << " does not exist\nPress any key to go back";
            getch(); 
        } 
    }

    void viewSubjects()
    {
        int grade = get_int("Enter Grade: ");
        if(grades.search(grade) != nullptr)
        {
            system("cls");
            cout << "List of Subjects taught in Grade " << grade  << ":" << endl;
            int count = subjects.displaySpecific(grade, Subject::printTitle, Subject::printTabularData);
            if(count == 0)
            {
                cout << "No subjects have been added for this grade\n";
            }
            cout << "Press any key to go back\n";
            getch();
            
        }
        else
        {
            cout << "Grade " << grade << " does not exist\nPress any key to go back";
            getch(); 
        } 
        
    }

    void addGrade()
    {
        Grade obj;
        int gradeID = get_int_in_range(1, 10, "Enter Grade ID: ", "Grade should be greater than 0 and less than 11\n");
        obj.setGradeID(gradeID);
        if(grades.search(obj) != nullptr)
        {
            cout << "Grade Already exists\nPress any key to go back";
            getch();
            return;
        }
        string gradeName = get_string("Enter Grade Name: ");
        int totalSubjects = get_int("Enter total Subjects: ");
        obj.setGradeID(gradeID);
        obj.setGradeName(gradeName);
        obj.setTotalSubjects(totalSubjects);
        grades.insertAtEnd(obj);
        cout << "Grade Added Successfully\nPress any key to go back";
        getch(); 

    }

    void addSection()
    {
        int gradeID = get_int("Enter Grade ID: ");
        if(grades.search(gradeID) != nullptr)
        {
            /* if(Management::viewEntries("section.txt", &Section::printTabularData, "", gradeID, false, true, &Section::getGradeID, false) == 2)
            {
                cout << "A Grade can only have two Sections\nPress any key to go back";
                getch();
                return;
            } */
            Section obj;
            string sectionName = get_string("Enter Section Name: ");
            obj.setGradeID(gradeID);
            upperString(sectionName);
            obj.setName(sectionName);
            if(sections.search(obj) != nullptr)
            {
                cout << "Section Already exists\nPress any key to go back";
                getch();
                return;
            }
            int totalCapacity = get_int_in_range(1, INT_MAX, "Enter total capacity of this section: ", "Capacity should be greater than 0\n");
            obj.setMaxStudents(totalCapacity);
            obj.setCurrentStudents(0);
            sections.insertAtEnd(obj);
            cout << "Section Added Successfully\nPress any key to go back";
            getch();
        }
        else
        {
            cout << "Grade " << gradeID << " does not exist\nPress any key to go back, add this Grade then Add Section";
            getch(); 
        }
        
    }

    void addSubject()
    {
        int gradeID = get_int("Enter Grade ID: ");
        node<Grade> * temp = grades.search(gradeID);
        if(temp != nullptr)
        {
            if(subjects.countInstances(temp->data)== temp->data.getTotalSubjects())
            {
                cout << "Maximum number of subjects have already been added for this grade\nPress any key to go back";
                getch();
                return;
            }
            Subject obj;
            string subjectID = get_string("Enter Subject ID: ");
            upperString(subjectID);
            obj.setSubID(subjectID);
            
            if(subjects.search(obj) != nullptr)
            {
                cout << "Subject Already exists\nPress any key to go back";
                getch();
                return;
            }
            string subjectName = get_string("Enter Subject Name: ");
            obj.setSubName(subjectName);
            obj.setGradeID(gradeID);
            subjects.insertAtEnd(obj);
            cout << "Subject Added Successfully\nPress any key to go back";
            getch();
        }
        else
        {
            cout << "Grade " << gradeID << " does not exist\nPress any key to go back, add this Grade then add a subject";
            getch(); 
        } 
    }

    void deleteGrade()
    {
        Section obj;
        Grade temp;
        int gradeID = get_int("Enter Grade ID to delete: ");
        if(grades.search(gradeID) != nullptr)
        {
            int count  = sections.countInstances(gradeID);
            if(count > 0)
            {
                cout << "This Grade has " << count << "section(s), Please delete the sections of this Grade first\nPress any key to go back";
                getch();
                return;
            }
        }
        else
        {
            cout << "Grade " << gradeID << " does not exist\nPress any key to go back";
            getch();
            return;
        }
        grades.deleteData(gradeID);
        while(subjects.deleteData(gradeID));
        cout << "Grade Deleted Successfully\nPress any key to go back";
        getch(); 
    }

    void deleteSection()
    {
        int gradeID = get_int("Enter Grade ID of the sections you want to delete: ");
        if(grades.search(gradeID))
        {
            string sectionName = get_string("Enter section name to delete: ");
            upperString(sectionName);
            string gradeAndSection = to_string(gradeID)+sectionName;
            node<Section> * temp = sections.search(gradeAndSection);
            if(temp != nullptr)
            {
                if(temp->data.getCurrentStudentsCount() != 0)
                {
                    cout << "Delete failed! This Grade's sections have students enrolled\nPress any key to back";
                }
                else
                {
                    sections.deleteData(gradeAndSection);
                    cout << "Section Deleted Successfully\nPress any key to go back";
                }
                
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

    void deleteSubject()
    {
        string subID = get_string("Enter Subject ID to delete: ");
        upperString(subID);
        node<Subject> * temp = subjects.search(subID);
        if(temp != nullptr)
        {
            Grade obj;
            obj.setGradeID(temp->data.getGradeID());
            if(students.countInstances(obj) >= 1)
            {
                cout << "Delete Failed!\n";
                cout << "The Grade to which this Subject belongs to has students Enrolled\nPress any key to go back";
                
            }
            else
            {
               /*  Class temp;
                string NA = "NA";
                saveChanges("class.txt", subID, temp, &Class::getSubid, true, true, &Class::setSubID, &NA); */
                subjects.deleteData(temp->data);
                cout << "Subject Deleted Successfully!\nPress any key to go back";
            }
        }
        else
        {
            cout << "Subject does not exist\nPress any key to go back";
        }
        getch(); 
    }

    public:

    int showOperations() override
    {
        
        int option;
        if(grades.getSize() != 0)
        {
            grades.displayAll(Grade::printTitle, Grade::printTabularData);
            
        }
        else
        {
            cout << "No Grades have been added yet\n";
        }
        cout << "\n1-> View Sections of a Grade\n";
        cout << "2-> View Subjects taught in a Grade\n";
        cout << "3-> Add Grade\n";
        cout << "4-> Add Section\n";
        cout << "5-> Add a Subject\n";
        cout << "6-> Delete a Grade\n";
        cout << "7-> Delete a Section\n";
        cout << "8-> Delete a Subject\n";
        cout << "9-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 9, "? ", "Invalid Option Selected, Please try Again\n");
        return option;
    }

    int performOperation(int option) override
    {
        switch(option)
        {
            //1-> View Sections of a Grade
            case 1:
            viewSections();
            break;

            //2-> View Subjects taught in a Grade
            case 2:
            viewSubjects();
            break;

            //3-> Add Grade
            case 3:
            addGrade();
            break;

            //4-> Add Section
            case 4:
            addSection();
            break;

            //5-> Add a Subject
            case 5:
            addSubject();
            break;

            //6-> Delete a Grade
            case 6:
            deleteGrade();
            break;
            
            //7-> Delete a Section
            case 7:
            deleteSection();
            break;

            //8-> Delete a Subject
            case 8:
            deleteSubject();
            break;
        }
        return option;
    }

    string showManagementType() override { return "GradeSectionManagement"; }

    //useful to implement the back operation
    int getNumberOfOperations() override { return 8; }
};

#endif