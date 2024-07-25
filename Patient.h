#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include <vector>
#include "Appointment.h"
#include "Session.h"

typedef struct date {
    int day;
    int month;
    int year;

    date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
} Date;

class Patient : public User {
    std::string medicalRecord;
    Date dateOfEntry;
    std::vector<Appointment *> appointments;

public:
    bool manageProfile(std::string Name, std::string EmailAddress);

    bool cancelAppointment(int doctorId, int sessionId);

    bool bookAppointment(int doctorId, int sessionId);

    std::string viewMedicalRecord();

    std::vector<Appointment *> viewBookedAppointments();

    std::vector<Session *> viewAvailableSessions(int doctorId);

    void set_medical_record(const std::string &medical_record);
};

#endif //PATIENT_H
