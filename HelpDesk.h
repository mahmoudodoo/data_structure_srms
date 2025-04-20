// HelpDesk.h
#ifndef HELPDESK_H
#define HELPDESK_H

#include <queue>
#include <string>

class HelpDesk {
private:
    std::queue<std::string> requestQueue;
    
public:
    void addRequest(const std::string& studentId);
    std::string processNextRequest();
    bool isEmpty() const;
};

#endif // HELPDESK_H