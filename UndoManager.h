#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H

#include "Student.h"
#include <stack>
#include <string>

// Forward declaration
class StudentList;

enum class OperationType { ADD, DELETE, UPDATE };

struct Operation {
    OperationType type;
    Student student;
    Student previousState;
    
    Operation(OperationType t, const Student& s, const Student& p = Student("", "", 0.0, "")) 
        : type(t), student(s), previousState(p) {}
};

class UndoManager {
private:
    std::stack<Operation> operationStack;
    
public:
    void recordOperation(OperationType type, const Student& student, const Student& previousState = Student("", "", 0.0, ""));
    bool undoLastOperation(StudentList& studentList);
};

#endif // UNDOMANAGER_H