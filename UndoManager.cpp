#include "UndoManager.h"
#include "StudentList.h"

void UndoManager::recordOperation(OperationType type, const Student& student, const Student& previousState) {
    Operation op(type, student, previousState);
    operationStack.push(op);
}

bool UndoManager::undoLastOperation(StudentList& studentList) {
    if (operationStack.empty()) {
        return false;
    }
    
    Operation lastOp = operationStack.top();
    operationStack.pop();
    
    switch (lastOp.type) {
        case OperationType::ADD:
            studentList.deleteStudent(lastOp.student.getId());
            break;
        case OperationType::DELETE:
            studentList.addStudent(lastOp.student);
            break;
        case OperationType::UPDATE:
            studentList.updateStudent(lastOp.student.getId(), lastOp.previousState);
            break;
    }
    
    return true;
}