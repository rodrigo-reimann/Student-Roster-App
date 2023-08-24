//
//  roster.h
//  ScriptingAndProgramming
//
//  Created by Rodrigo Baston on 2023-08-16.
//

#ifndef roster_h
#define roster_h

#include "student.h"

class Roster {
public:
    Student *classRosterArray[5];
    
    Roster(); // Constructor declaration
    ~Roster(); // Destructor declaration
    
    void parse(const std::string studentData[]); //parse function
    
    void add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); // add function with parameters
    
    void add(Student* student); //add function with student object
    
    void remove(std::string studentID);
    
    void printAll();
    
    void printAverageDaysInCourse(std::string studentID);
    
    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
};



#endif /* roster_h */
