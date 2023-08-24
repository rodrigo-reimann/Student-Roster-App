//
//  student.cpp
//  ScriptingAndProgramming
//
//  Created by Rodrigo Baston on 2023-08-16.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "student.h"

//Constructor implementation
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram): studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    
    for (int i = 0; i < 3; ++i) {
        this -> daysToComplete[i] = daysToComplete[i];
    }
    
}

//Accessors implementation
std::string Student::getStudentID() { return studentID; }
std::string Student::getFirstName() { return firstName; }
std::string Student::getLastName() { return lastName; }
std::string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysToComplete() { return  daysToComplete; }
DegreeProgram Student::getDegreeProgram () { return degreeProgram;}

//Mutators implementation
void Student::setStudentID(std::string ID) { studentID = ID; }
void Student::setFirstName(std::string fName) { firstName = fName; }
void Student::setLastName(std::string lName) { lastName = lName; }
void Student::setEmailAddress(std::string email) { emailAddress = email; }
void Student::setAge(int sAge) { age = sAge; }
void Student::setDaysToComplete(int days[3]) {
    for (int i = 0; i < 3; ++i) {
        daysToComplete[i] = days[i];
    }
}
void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }


//Print student information implementation
void Student::print() {
    
    std::cout << studentID << "    " 
    << "First Name: " << firstName << "   "
    << "Last Name: " << lastName << "    "
    << "Age: " << age << "   "
    << "Days in Course: ";
    
    std::cout << "{";
    for (int j = 0; j < 3; ++j) {
        if (j == 2) {
            std::cout << daysToComplete[j] << "}";
        } else {
            std::cout << daysToComplete[j] << ", ";
        }
    }
    std::cout << "   " << "Degree Program: ";
   
    switch (degreeProgram) {
        case SECURITY:
            std::cout << "SECURITY";
            break;
        case NETWORK:
            std::cout << "NETWORK";
            break;
        case SOFTWARE:
            std::cout << "SOFTWARE";
            break;
        default:
            break;
    }
    std::cout << std::endl;
}
