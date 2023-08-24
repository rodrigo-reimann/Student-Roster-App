//
//  roster.cpp
//  ScriptingAndProgramming
//
//  Created by Rodrigo Baston on 2023-08-16.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

#include "roster.h"

using namespace std;

//Constructor implementation
Roster::Roster() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

//Destructor implementation
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

//Parse method implementation,
//Look for find or at documentation
void Roster::parse(const string studentData[]) {
    for (int i = 0; i < 5; ++i) {
        istringstream ss (studentData[i]);
        string ID;
        getline(ss, ID, ',');
        string fName;
        getline(ss, fName, ',');
        string lName;
        getline(ss, lName, ',');
        string email;
        getline(ss, email, ',');
        int tAge;
        ss >> tAge;
        ss.ignore(); //Skip comma
        int days1;
        ss >> days1;
        ss.ignore(); //Skip comma
        int days2;
        ss >> days2;
        ss.ignore(); //Skip comma
        int days3;
        ss >> days3;
        ss.ignore(); //Skip comma
        string sDegree;
        DegreeProgram degree;
        getline(ss, sDegree, ',');
        if (sDegree == "SECURITY") {
            degree = SECURITY;
        } else if (sDegree == "SOFTWARE") {
            degree = SOFTWARE;
        } else {
            degree = NETWORK;
        }
        
        //Add newly created object to classRosterArray
        add(ID, fName, lName, email, tAge, days1, days2, days3, degree);
        
    }
}

//Add method implementation
void Roster::add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
    
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = student;
            break;
        }
    }
}

//Add method overload with Student object as parameter
void Roster::add(Student* student) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = student;
            break;
        }
    }
}

//Remove method implementation
void Roster::remove(string studentID) {
    bool noObjectCheck = true;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i] -> getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            noObjectCheck = false;
            break;
        }
    }
    if (noObjectCheck == true) {
        cout << "Student with this ID not found." << endl;
    }
}


//Print All method implementation
void Roster::printAll() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i] -> print();
        }
    }
}
            
            
//Print Average Days in Course method implementation
void Roster::printAverageDaysInCourse(std::string studentID) {
    double sum = 0;
    double avg = 0;
    
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i] -> getStudentID() == studentID) {
            cout << "Average days in course for " << studentID << ": ";
            int* days = classRosterArray[i] -> getDaysToComplete();
            for (int j = 0; j < 3; ++j) {
                sum += days[j];
            }
            avg = sum / 3;
            cout << avg << endl;
            break;
        }
    }
}


//Print Invalid Emails method implementation
void Roster::printInvalidEmails() {
    char atCharToFind = '@';
    char periodCharToFind = '.';
    char spaceCharToFind = ' ';
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr
            && (classRosterArray[i] -> getEmailAddress().find(atCharToFind) == string::npos
            || classRosterArray[i] -> getEmailAddress().find(periodCharToFind) == string::npos
            || classRosterArray[i] -> getEmailAddress().find(spaceCharToFind) != string::npos)) {
            cout << "Invalid email: " << classRosterArray[i] -> getEmailAddress() << endl;
        }
    }
    
}

//Print by Degree Program implementation
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] -> getDegreeProgram() == degreeProgram) {
            cout << classRosterArray[i] -> getStudentID() << "    "
            << "First Name: " << classRosterArray[i] -> getFirstName() << "   "
            << "Last Name: " << classRosterArray[i] -> getLastName() << "    "
            << "Email: " << classRosterArray[i] -> getEmailAddress() << "   "
            << "Age: " << classRosterArray[i] -> getAge() << "   "
            << "Days to Complete: ";
            int* days = classRosterArray[i] -> getDaysToComplete();
            for (int j = 0; j < 3; ++j) {
                cout << days[j] << ", ";
            }
            cout << endl;
        }
    }
}
