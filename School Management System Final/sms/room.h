#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <sstream>
#include <regex>
#include <stdexcept>
#include <ctype.h>

//incomplete

class Room
{
    friend std::istream& operator>>(std::istream&, Room &);
    private:
    int roomID;
    char floor;
    std::string roomName;
    int roomCapacity;

    bool isRoomFormatValid(std::string room)
    {
        return std::regex_match(room, std::regex("^([GFS]|[gfs])[-][1-9]$"));
    }

    public:
    Room() = default;
    Room(int id, char floor, int capacity)
    : roomID(id), floor(floor), roomCapacity(capacity)
    {
        std::ostringstream oss;
        oss << floor << "-" << roomID;
        roomName = oss.str();
    }

    Room(std::string room)
    {
        setRoomName(room);
    }
    int getRoomID() const {return roomID;}
    char getRoomFloor() const {return floor;}
    std::string getRoomName() const {return roomName;}
    int getRoomCapacity() const {return roomCapacity;}
    void setRoomID(int id) {roomID = id;}
    void setRoomFloor(char f) {floor = f;}
    void setRoomCapacity(int capacity) {roomCapacity = capacity;}
    void setRoomName(std::string room)
    {
        if(isRoomFormatValid(room))
        {
            std::istringstream iss(room);
            iss >> floor;
            iss.ignore();
            iss >> roomID;
            floor = toupper(floor);
            roomName = room;
        }
        else
        {
            throw std::runtime_error("Invalid Room Format");
        }
    }

    bool operator==(const Room &r)
    {
        if(roomName == r.getRoomName())
        {
            return true;
        }
        return false;
    }

    bool operator==(const string &s)
    {
        if(roomName == s)
        {
            return true;
        }
        return false;
    }

    bool operator!=(const Room &r)
    {
        if(!(*this==r))
        {
            return true;
        }
        return false;
    }

    void printTitle()
    {
        cout << "| " <<  left << setw(8) << "Room ID" << "| " << setw(11) << "Room Floor" << "| " << 
        setw(14) << "Room Capacity" << "| " << setw(10) << "Room Name" << "|\n" ;
    }

    void printTabularData()
    {
        cout << "| " <<  left << setw(8) << roomID << "| " << setw(11) << floor << "| " << 
        setw(14) << roomCapacity << "| " << setw(10) << roomName << "|\n" ;
    }
    
};

std::istream& operator>>(std::istream& in, Room &obj)
{
    in >> obj.roomID >> obj.floor >> obj.roomCapacity >> obj.roomName;
    in.ignore();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Room &obj)
{
    out << obj.getRoomID() << " " << obj.getRoomFloor() << " " << obj.getRoomCapacity() << " " 
    << obj.getRoomName() << "\n";
    return out;
}

std::string get_room_name(std::string prompt = "Enter Room Name [G/F/S/g/f/s]-[1-9]: ")
{
    std::string roomName; 
    while(true)
    {
        roomName = get_string(prompt);
        if(roomName == "NA")
        {
            break;
        }
        try
        {
            Room temp = roomName;
            break;
        }
        catch (const runtime_error &err)
        {
            std::cout << err.what() << ", Please try again\n";
        }

    }
    return roomName;
}

//When opening the program for first time, these will exist initially
/* Room r1(1, 'G', 30);
Room r2(2, 'G', 40);
Room r3(1, 'F', 30);
Room r4(2, 'F', 40); */
#endif