#include "Appointment.h"

Appointment::Appointment(int patientID, int doctorID, int sessionID) {
    this->patientID = patientID;
    this->doctorID = doctorID;
    this->sessionID = sessionID;
}

int Appointment::getSessionId() const {
    return sessionID;
}