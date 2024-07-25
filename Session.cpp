#include "Session.h"

int Session::sessionCounter = 0;

Session::Session(std::string &dayOfWeek, std::string &startTime, std::string &endTime) {
    this->sessionId = ++sessionCounter;
    this->dayOfWeek = dayOfWeek;
    this->startTime = startTime;
    this->endTime = endTime;
}

