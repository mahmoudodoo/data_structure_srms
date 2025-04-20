// StudentList.h
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"
#include <vector>
#include <string>

struct Node {
    Student data;
    Node* next;
    Node(const Student& student) : data(student), next(nullptr) {}
};

class StudentList {
private:
    std::vector<Student> studentsArray; // Array implementation
    Node* head; // Linked list implementation
    int arraySize;
    int arrayCapacity;
    
    // Helper methods
    void addToArray(const Student& student);
    void addToLinkedList(const Student& student);
    void deleteFromArray(const std::string& id);
    void deleteFromLinkedList(const std::string& id);
    
public:
    StudentList(int capacity = 100);
    ~StudentList();
    
    void addStudent(const Student& student);
    bool deleteStudent(const std::string& id);
    bool updateStudent(const std::string& id, const Student& updatedStudent);
    Student* searchStudent(const std::string& id);
    void displayAll() const;
};

#endif // STUDENTLIST_H