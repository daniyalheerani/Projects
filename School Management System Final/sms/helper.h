/*
Definitions of some helper functions
*/
#ifndef HELPER_H
#define HELPER_H

//Functions will be added as needed

#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include "time.h"


int get_int(std::string prompt = "Enter: ")
{
    std::string temp;
    int a;
    std::istringstream iss;
	do
	{
        iss.clear();
        std::cout << prompt;
        getline(std::cin, temp);
        iss.str(temp);
        iss >> a;
        if(iss.fail())
        {
            std::cout << "Please, input an integer\n";
        }
	}
    while (iss.fail());
    return a;
}

std::string get_digits(int digits, std::string prompt = "Enter: "
, std::string reprompt = "Invalid digits, Please try again\n")
{
    std::string num;
    std::istringstream iss;
    long long int a;
    do
    {
        iss.clear();
        std::cout << prompt;
        getline(std::cin, num);
        iss.str(num);
        iss >> a;
        if(iss.fail())
        {
            std::cout << "Please make sure you are entering only numbers\n";
        }
        else if(num.size() != digits)
        {
            std::cout << reprompt;
        }
    } 
    while (num.size() != digits || iss.fail());
    return num;
}

int get_int_in_range(int lowerLimit = INT_MIN, int upperLimit = INT_MAX, 
std::string prompt = "Enter: ", std::string reprompt = "Invalid, Try again\n")
{
    /* used to take an integer in a specified range lowerLimit-upperLimit */
    int a;
	do
	{
        a = get_int(prompt);
        if(a < lowerLimit || a > upperLimit)
        {
            std::cout << reprompt;
        }
	}
    while (a < lowerLimit || a > upperLimit);
    return a;
}

char get_char(std::string prompt = "Enter: ")
{
    /*used to take only one character time user */
    std::string temp;
    char c;
    std::istringstream iss;
	while(true)
	{
        iss.clear();
        std::cout << prompt;
        getline(std::cin, temp);
        iss.str(temp);
        iss >> c;
        if(temp.size() == 0)
        {
            std::cout << "Please enter something!\n";
        }
        else if(temp.size() > 1)
        {
            std::cout << "Please enter only one character!\n";
        }
        else
        {
            break;
        }
	}
    return c;
}

char get_specific_chars(std::string specificChars, std::string prompt = "Enter: ")
{
    char ch;
    while(true)
    {
        ch = tolower(get_char(prompt));
        if(specificChars.find(ch) == std::string::npos)
        {
            std::cout << "Please make sure you enter characters which are allowed\n";
        }
        else
        {
            break;
        }
    }
    return ch;
}

std::string get_string(std::string prompt = "Enter :")
{
    /*makes sure that string is not empty */
    std::string temp;
    do
    {
        std::cout << prompt;
        getline(std::cin, temp);
        if(temp.size() == 0)
        {
            std::cout << "Please enter something!\n";
        }
    } 
    while(temp.size() == 0);
    return temp;
}

void lowerString(std::string &str)
{
    for(int i = 0; i < str.size(); ++i)
    {
        str[i] = tolower(str[i]);
    }
}

void upperString(std::string &str)
{
    for(int i = 0; i < str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

bool isStringDay(std::string &day)
{
    std::string days[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    lowerString(day);
    for(int i = 0; i < 7; ++i)
    {
       if(day == days[i])
       {
          return true;
       }
    }
    return false;
}

std::string get_day(std::string prompt = "Enter day: ")
{
    std::string day; 
    while(true)
    {
        day = get_string("Enter day: ");
        if(isStringDay(day))
        {
            break;
        }
        std::cout << "Invalid day, Please try again\n";
    }
    return day;
}

Time get_hourly_time(std::string prompt = "Enter Hourly Time: ")
{
    Time time;
    while(true)
    {
        try
        {
            time = get_string(prompt);
            if(time.getMinute() == 0)
            {
                break;
            }
            std::cout << "Please enter Hourly Time like 11:00, only\n";
        }
        catch(const std::runtime_error &err)
        {
            std::cout << err.what() << ", Please try again\n";
        }
    }
    return time;
}


#endif
