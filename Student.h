#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string id;
    std::string name;
    double gpa;
    std::string department;
    
public:
    Student() : id(""), name(""), gpa(0.0), department("") {}  // Default constructor
    Student(std::string id, std::string name, double gpa, std::string department);
    
    // Getters
    std::string getId() const;
    std::string getName() const;
    double getGpa() const;
    std::string getDepartment() const;
    
    // Setters
    void setName(std::string name);
    void setGpa(double gpa);
    void setDepartment(std::string department);
    
    void display() const;
};

#endif // STUDENT_H