#include "StudentList.h"
#include <iostream>

StudentList::StudentList(int capacity) : arrayCapacity(capacity), arraySize(0), head(nullptr) {}

StudentList::~StudentList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void StudentList::addToArray(const Student& student) {
    if (arraySize < arrayCapacity) {
        studentsArray.push_back(student);
        arraySize++;
    }
}

void StudentList::addToLinkedList(const Student& student) {
    Node* newNode = new Node(student);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void StudentList::addStudent(const Student& student) {
    addToArray(student);
    addToLinkedList(student);
}

void StudentList::deleteFromArray(const std::string& id) {
    for (auto it = studentsArray.begin(); it != studentsArray.end(); ++it) {
        if (it->getId() == id) {
            studentsArray.erase(it);
            arraySize--;
            break;
        }
    }
}

void StudentList::deleteFromLinkedList(const std::string& id) {
    if (head == nullptr) return;
    
    if (head->data.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr && current->next->data.getId() != id) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

bool StudentList::deleteStudent(const std::string& id) {
    bool found = false;
    
    // Search in array
    for (const auto& student : studentsArray) {
        if (student.getId() == id) {
            found = true;
            break;
        }
    }
    
    if (found) {
        deleteFromArray(id);
        deleteFromLinkedList(id);
        return true;
    }
    
    return false;
}

bool StudentList::updateStudent(const std::string& id, const Student& updatedStudent) {
    // Update in array
    for (auto& student : studentsArray) {
        if (student.getId() == id) {
            student = updatedStudent;
            
            // Update in linked list
            Node* current = head;
            while (current != nullptr) {
                if (current->data.getId() == id) {
                    current->data = updatedStudent;
                    return true;
                }
                current = current->next;
            }
            return true;
        }
    }
    return false;
}

Student* StudentList::searchStudent(const std::string& id) {
    // Search in array (could also search in linked list)
    for (auto& student : studentsArray) {
        if (student.getId() == id) {
            return &student;
        }
    }
    return nullptr;
}

void StudentList::displayAll() const {
    std::cout << "\nStudent Records (Array):\n";
    for (const auto& student : studentsArray) {
        student.display();
    }
    
    std::cout << "\nStudent Records (Linked List):\n";
    Node* current = head;
    while (current != nullptr) {
        current->data.display();
        current = current->next;
    }
}