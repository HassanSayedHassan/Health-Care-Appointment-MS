#ifndef APPOINTMENT_H
#define APPOINTMENT_H

class Appointment {
    int patientID;
    int doctorID;
    int sessionID;
public:
    Appointment(int patientID, int doctorID, int sessionID);

    int getSessionId() const;
};

#endif