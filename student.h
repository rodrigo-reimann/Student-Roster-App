//
//  student.h
//  ScriptingAndProgramming
//
//  Created by Rodrigo Baston on 2023-08-16.
//

#ifndef student_h
#define student_h

#include "degree.h"
#include <string>

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;
    
public:
    //Constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
    
    //Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getDaysToComplete();
    DegreeProgram getDegreeProgram();
    
    //Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int sAge);
    void setDaysToComplete(int daysToComplete[3]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //Print student object information
    void print();
    
    
    
};



#endif /* student_h */
