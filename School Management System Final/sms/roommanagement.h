#ifndef ROOMMANAGEMENT_H
#define ROOMMANAGEMENT_H

#include "management.h"

class ClassAndRoomManagement: public Management
{
    private:
    //Sub Operations of Operation 1-> View Classes
    int showSubOperations()
    {
        int option;
        cout << "\n1-> Change Teacher\n";
        cout << "2-> Change Section\n";
        cout << "3-> Change Subject\n";
        cout << "4-> Delete Class\n";
        cout << "5-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 5, "? ", "Invalid Option Selected, Please try Again\n");
        return option;
    }

    void changeTeacher(Class &object)
    {
        system("cls");
        int teacherID = get_int_in_range(-1, INT_MAX, "Enter Teacher ID (-1) to unassign: ", "ID should be greater than 0\n");
        Node <Teacher> * temp = teachers.search(teacherID);
        if(teacherID == -1 || temp != nullptr)
        {
            object.assignTeacherID(teacherID);
            cout << "Changed Successfully! ";
        }
        else
        {
            if(teacherID == 0)
            {
                cout << "Teacher ID can not be 0, ";
            }
            else
            {
                cout << "Teacher does not exist in the database, ";
            }
        }
        cout << "Press any key to go back";
        getch();
    }

    void changeSection(Class &object)
    {   
        system("cls");
        int grade = get_int_in_range(1, 10, "Enter Grade: ", "Grade should be between 1-10\n");
        string section = get_string("Enter Section (Enter \"NA\" ->to unassign): ");
        upperString(section);
        string gradeAndSection = to_string(grade)+section;
        node <Section>* temp = sections.search(gradeAndSection);
        if(section == "NA")
        {
            object.setSectionName("NA");
            object.setGradeID(-1);
            cout << "Changed Successfully! ";

        }
        else if(temp != nullptr)
        {
            string roomName = object.getRoomName();
            node <Room>* room = rooms.search(roomName);
            if(temp->data.getCurrentStudentsCount() > room->data.getRoomCapacity())
            {
                cout << "\nRoom Capacity is less than the current number of students enrolled in the section, ";
            }
            else
            {
                object.setGradeID(grade);
                object.setSectionName(section);
                object.assignTeacherID(-1);
                object.setSubID("NA");
                cout << "Changed Successfully! ";
            }
        }
        
        else
        {
            cout << "Delete Failed! "<< section << "-" << grade << " does not exist, ";
        }
        cout << "Press any key to go back";
        getch();
    }

    void changeSubject(Class &object)
    {
        system("cls");
        string subID = get_string("Enter Subject ID (Enter \"NA\"->to unassign): ");
        node <Subject>* temp = subjects.search(subID);
        if(subID == "NA" || temp != nullptr)
        {
            if(subID == "NA")
            {
                object.setSubID("NA");
                cout << "Changed Successfully! ";

            }
            else if(temp->data.getGradeID() == object.getGradeID())
            {
                object.setSubID(subID);
                cout << "Changed Successfully! ";
            }
            else
            {
                cout << subID << " grade is " << temp->data.getGradeID() << 
                ", while this class is for grade " << object.getGradeID() << ", ";
            }
            
        }
        else
        {
            cout << "Subject does not exist in the database, ";
        }
        cout << "Press any key to go back";
        getch();
    }

    bool deleteClass(Class &object)
    {
        system("cls");
        if(object.getTeacherID() == -1 && object.getSectionName() == "NA")
        {   
            classes.deleteData(object);
            cout << "Deleted successfully! Press any key to go back";
            getch();
            return true;
        }
        else
        {
            cout << "Can not delete, This Class is of " << object.getSectionName() <<"-"<<object.getGradeID() << " section and also has a teacher assigned\n";
            cout << "Press any key to go back";
            getch();
        }
        return false; 
    }

    node<Class>* viewClasses(char c)
    {
        //c : if 'r' shows classes by Room or if 't' shows classes by teacher
        string roomName;
        int teacherID;
        int entries;
        if(c == 'r')
        {
            roomName = get_room_name("Enter Room Name [G/F/S/g/f/s]-[1-9]: ");
            system("cls");
            cout << "All classes in Room " << roomName << ":\n";
            entries = classes.displaySpecific(roomName, Class::printTitle, Class::printTabularData);

        }
        else if(c == 't')
        {
            if(!teachers.isEmpty())
            {   
                teacherID = get_int_in_range(1, INT_MAX, "Enter Teacher ID to view classes: ", "ID should be greater than 0\n");
                system("cls");
                cout << "All classes by Teacher ID: " << teacherID << ":\n";
                Teacher obj;
                obj.setID(teacherID);
                entries = classes.displaySpecific(obj, Class::printTitle, Class::printTabularData);
            }
            else
            {
                cout << "No Teachers found in the database\n Press any key to go back";
                getch();
            }
           
        }

        if(entries != 0)
        {
            char c = get_specific_chars("yn", "\n\nDo you want to view a Specific class to change it (y/n)? ");
            {
                if(c == 'y')
                {
                    int classID = get_int_in_range(1, INT_MAX, "Enter Class ID to view a specific Class: ", "ID should be greater than 0\n");
                    node<Class>* temp = classes.search(classID);
                    if(temp!= nullptr)
                    {   
                        system("cls");
                        return temp;
                    }
                    cout << "\n\nClass does not exist, Press any key to go back";
                    getch();
                    return nullptr;
                }
            }
        }
        else if(c == 'r')
        {
            cout << "No classes have been assigned to this room\nPress any key to go back";
            getch();
        }
        else
        {
            cout << "No classes have been assigned to this teacher\nPress any key to go back";
            getch();
        }
        return nullptr;
    }

    void addClass()
    {
        system("cls");
        string roomName = get_room_name();
        string day = get_day();
        Time fromTime = get_hourly_time("Enter time the class will start from: ");
        Time toTime(fromTime.getHour()+1, 0);
        Class obj(0, roomName, "NA", -1, day, fromTime.toString(), toTime.toString(), -1, "NA");

        if(classes.search(obj) != nullptr)
        {   
            cout << "\nThis class will clash with the following classe(s):\n";
            classes.displaySpecific(obj, Class::printTitle, Class::printTabularData);
            cout << "\nPlease Try again by setting different room, or day, or time\nPress any key to go back";
            getch();
            return;
        }
        obj.setClassID(classes.getMax().getClassID()+1);
        classes.insertAtEnd(obj);
        cout << "\nClass added Successfully!\nPlease go to the view Classes By Room option to assign Section, Teacher, or Subject\n";
        cout << "Press any key to go back";
        getch();
    }

    void addRoom()
    {
        system("cls");
        string roomName = get_room_name();
        if(rooms.search(roomName) != nullptr)
        {
            cout << "Room already Exists, Press any key to go back";
            getch();
            return;
        }
        Room object;
        int roomCapacity = get_int_in_range(1, INT_MAX, "Enter room max capacity: ", "Capacity should be greater than 0\n");
        object.setRoomName(roomName);
        object.setRoomCapacity(roomCapacity);
        rooms.insertAtEnd(object);
        cout << "\nRoom Added Successfully, Press any key to go back";
        getch();
    }

    void deleteRoom()
    {
        system("cls");
        string roomName = get_room_name();
        if(rooms.search(roomName) != nullptr)
        {
            if(classes.search(roomName) != nullptr)
            {
                cout << "Cannot delete! " << roomName << " is assigned to the following classes:\n";
                classes.displaySpecific(roomName, Class::printTitle, Class::printTabularData);
                cout << endl;
            }
            else
            {
                rooms.deleteData(roomName);
                cout << "\nRoom Deleted Successfully, ";
            }
        }
        else
        {
            cout << "\n" << roomName << " does not exist, ";
        }
        cout << "Press any key to go back";
        getch();
    }

    public:
    int showOperations() override
    {
        int option;
        if(rooms.getSize() != 0)
        {
            rooms.displayAll(Room::printTitle, Room::printTabularData);
            
        }
        else
        {
            cout << "No rooms found in the database\n";
        }
        cout << "\n1-> View classes By Room\n";
        cout << "2-> View Classes By Teacher\n";
        cout << "3-> Add a Class\n";
        cout << "4-> Add a Room\n";
        cout << "5-> Delete a room\n";
        cout << "6-> Back\n";
        cout << "0-> Quit" << endl;
        option = get_int_in_range(0, 6, "? ", "Invalid Option Selected, Please try Again\n");
        return option;
    }

    

    int performOperation(int option) override
    {
        switch(option)
        {
            //1-> ViewClassesByRoom or 2-> ViewClassesByTeacher
            case 1 ... 2:
            {
                node <Class>* obj;
                if(option == 1)
                {
                    obj =  viewClasses('r');
                }
                else
                {
                    obj = viewClasses('t');
                }
                while(obj != nullptr)
                {
                    system("cls");
                    obj->data.printData();
                    int option2 = showSubOperations();
                    if(option2 != 0 && option2 != 5)
                    {
                        switch(option2)
                        {
                            //1-> Change Teacher
                            case 1:
                            changeTeacher(obj->data);
                            break;

                            //2-> Change Section
                            case 2:
                            changeSection(obj->data);
                            break;

                            //3-> Change Subject
                            case 3:
                            changeSubject(obj->data);
                            break;

                            //4-> Delete Class
                            case 4:
                            {
                                if(deleteClass(obj->data))
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
                break;
                
            }
            //3-> Add a Class
            case 3:
            addClass();
            break;

            //4-> Add a room
            case 4:
            addRoom();
            break;

            //5-> Delete a Room
            case 5:
            deleteRoom();
            break;
        }
        return option;
    }

    //useful to implement the back operation
    int getNumberOfOperations() override { return 5; }
    string showManagementType() override { return "roommanagement"; } 

};


#endif