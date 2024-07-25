#ifndef DOCTOR_H
#define DOCTOR_H

#include <vector>
#include "user.h"
#include "Patient.h"
#include "Session.h"
#include "Appointment.h"


class Doctor : public User {
    int salary;
    std::string specialization;
    std::vector<Session *> availableSessions;
    std::vector<Appointment *> appointment;

public:
    Doctor(std::string &name, std::string &emailAddress, std::string &password,
           int salary, std::string specialization);

    /* getters */
    std::string getSpecialization() const;

    int getSalary() const;

    std::vector<Session *> getAllSessions();

    /* setters */
    void setSpecialization(const std::string &specialization);

    void setSalary(const int salary);

    bool updateMedicalRecord(Patient *patient, const std::string &medicalRecord);

    bool addAvailableSession(Session *session);

    bool removeSession(Session *session);

    std::vector<Appointment *> viewAppointments();

    void addAppointment(Appointment *appointment);

    void removeAppointment(int sessionId);

    bool isFreeSession(int sessionId);

    ~Doctor();
};

#endif
