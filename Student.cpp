#include "Student.h"
#include <iostream>

Student::Student(std::string id, std::string name, double gpa, std::string department)
    : id(id), name(name), gpa(gpa), department(department) {}

std::string Student::getId() const { return id; }
std::string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }
std::string Student::getDepartment() const { return department; }

void Student::setName(std::string name) { this->name = name; }
void Student::setGpa(double gpa) { this->gpa = gpa; }
void Student::setDepartment(std::string department) { this->department = department; }

void Student::display() const {
    std::cout << "ID: " << id 
              << ", Name: " << name 
              << ", GPA: " << gpa 
              << ", Department: " << department 
              << std::endl;
}