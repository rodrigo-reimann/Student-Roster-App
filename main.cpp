//
//  main.cpp
//  ScriptingAndProgramming
//
//  Created by Rodrigo Baston on 2023-08-16.
//

#include <iostream>
#include <sstream>
#include <string>
#include "degree.h"
#include "roster.h"

using namespace std;

int main() {

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Rodrigo,Reimann,rreim12@wgu.edu,33, 20,25,30,SOFTWARE"};
    
    //Print my application, course title, programming language used, my WGU student ID, and my name
    cout << "Course: Scripting and Programming - Applications — C867, Language: C++, Student ID: 010629417, Name: Rodrigo Reimann Baston" << endl;
    
    Roster classRoster; //Create a Roster object
    classRoster.parse(studentData); //Parse the studentData array into classRoster
    classRoster.printAll(); //Print all students
    classRoster.printInvalidEmails(); //Print invalid emails
    
    //Loop through classRosterArray inside the instantiated classRoster and print average days in course for each student using student ID as parameter
    for (int i = 0; i < 5; ++i) {
        string studentID = classRoster.classRosterArray[i] -> getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    
    classRoster.printByDegreeProgram(SOFTWARE); //Print all students for a particular degree program
    classRoster.remove("A3");
    classRoster.printAll(); //Print all students
    classRoster.remove("A3"); //Attempt to remove student A3 again and print an error message
    
    classRoster.~Roster(); //Implement destructor to release the memory that was allocated dynamically in Roster
    
    return 0;
}
