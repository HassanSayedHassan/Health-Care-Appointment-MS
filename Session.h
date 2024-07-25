#ifndef SESSION_H
#define SESSION_H


#include <string>

class Session {
    int sessionId;
    static int sessionCounter;
    std::string dayOfWeek;
    std::string startTime;
    std::string endTime;

    Session(std::string& dayOfWeek,std::string& startTime,std::string& endTime);
};


#endif
