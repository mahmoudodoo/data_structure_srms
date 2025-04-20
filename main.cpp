// main.cpp
#include <iostream>
#include <limits>
#include "StudentList.h"
#include "UndoManager.h"
#include "HelpDesk.h"

void displayMenu() {
    std::cout << "\nStudent Record Management System\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Delete Student\n";
    std::cout << "3. Update Student\n";
    std::cout << "4. Search Student\n";
    std::cout << "5. Display All Students\n";
    std::cout << "6. Undo Last Operation\n";
    std::cout << "7. Add Help Request\n";
    std::cout << "8. Process Next Help Request\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

Student getStudentInput() {
    std::string id, name, department;
    double gpa;
    
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    
    std::cout << "Enter Student Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Enter Student GPA: ";
    std::cin >> gpa;
    
    std::cout << "Enter Student Department: ";
    std::cin.ignore();
    std::getline(std::cin, department);
    
    return Student(id, name, gpa, department);
}

int main() {
    StudentList studentList;
    UndoManager undoManager;
    HelpDesk helpDesk;
    
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        
        switch(choice) {
            case 1: {
                Student student = getStudentInput();
                studentList.addStudent(student);
                undoManager.recordOperation(OperationType::ADD, student);
                std::cout << "Student added successfully.\n";
                break;
            }
            case 2: {
                std::string id;
                std::cout << "Enter Student ID to delete: ";
                std::cin >> id;
                
                Student* studentToDelete = studentList.searchStudent(id);
                if (studentToDelete) {
                    Student temp = *studentToDelete;
                    if (studentList.deleteStudent(id)) {
                        undoManager.recordOperation(OperationType::DELETE, temp);
                        std::cout << "Student deleted successfully.\n";
                    } else {
                        std::cout << "Failed to delete student.\n";
                    }
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 3: {
                std::string id;
                std::cout << "Enter Student ID to update: ";
                std::cin >> id;
                
                Student* studentToUpdate = studentList.searchStudent(id);
                if (studentToUpdate) {
                    Student previousState = *studentToUpdate;
                    Student updatedStudent = getStudentInput();
                    
                    if (studentList.updateStudent(id, updatedStudent)) {
                        undoManager.recordOperation(OperationType::UPDATE, updatedStudent, previousState);
                        std::cout << "Student updated successfully.\n";
                    } else {
                        std::cout << "Failed to update student.\n";
                    }
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 4: {
                std::string id;
                std::cout << "Enter Student ID to search: ";
                std::cin >> id;
                
                Student* student = studentList.searchStudent(id);
                if (student) {
                    student->display();
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case 5: {
                studentList.displayAll();
                break;
            }
            case 6: {
                if (undoManager.undoLastOperation(studentList)) {
                    std::cout << "Undo operation successful.\n";
                } else {
                    std::cout << "No operations to undo.\n";
                }
                break;
            }
            case 7: {
                std::string id;
                std::cout << "Enter Student ID for help request: ";
                std::cin >> id;
                helpDesk.addRequest(id);
                std::cout << "Help request added to queue.\n";
                break;
            }
            case 8: {
                if (!helpDesk.isEmpty()) {
                    std::string id = helpDesk.processNextRequest();
                    std::cout << "Processing help request for student ID: " << id << "\n";
                    // Here you would typically implement the help desk logic
                } else {
                    std::cout << "No pending help requests.\n";
                }
                break;
            }
            case 9: {
                std::cout << "Exiting program...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 9);
    
    return 0;
}