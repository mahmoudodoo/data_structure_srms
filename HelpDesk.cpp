#include "HelpDesk.h"

void HelpDesk::addRequest(const std::string& studentId) {
    requestQueue.push(studentId);
}

std::string HelpDesk::processNextRequest() {
    if (requestQueue.empty()) {
        return "";
    }
    
    std::string nextRequest = requestQueue.front();
    requestQueue.pop();
    return nextRequest;
}

bool HelpDesk::isEmpty() const {
    return requestQueue.empty();
}