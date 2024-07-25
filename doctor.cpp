#include "doctor.h"
#include "local_data.h"

Doctor::Doctor(std::string &name, std::string &emailAddress, std::string &password,
               int salary = 0, std::string specialization = "") : User(name, emailAddress, password) {
    this->salary = salary;
    this->specialization = specialization;
    doctors[this->getId()] = this;

}

std::string Doctor::getSpecialization() const {
    return specialization;
};

int Doctor::getSalary() const {
    return salary;
}

void Doctor::setSpecialization(const std::string &specialization) {
    this->specialization = specialization;
}

void Doctor::setSalary(const int salary) {
    this->salary = salary;
}

bool Doctor::updateMedicalRecord(Patient *patient, const std::string &medicalRecord) {
    patient->set_medical_record(medicalRecord);
    return true;
}

bool Doctor::addAvailableSession(Session *session) {
    availableSessions.push_back(session);
    return true;
}

bool Doctor::removeSession(Session *session) {
    availableSessions.erase(std::remove(availableSessions.begin(), availableSessions.end(), session),
                            availableSessions.end());
    return true;
}

std::vector<Appointment *> Doctor::viewAppointments() {
    return appointment;
}

void Doctor::addAppointment(Appointment *appointment) {
    this->appointment.push_back(appointment);
}

bool Doctor::isFreeSession(int sessionId) {
    for (Appointment *currentAppointment: appointment) {
        if (sessionId == currentAppointment->getSessionId()) return false;
    }
    return true;
}

void Doctor::removeAppointment(int sessionId) {
    for (auto it = appointment.begin(); it != appointment.end(); ++it) {
        if ((*it)->getSessionId() == sessionId) {
            appointment.erase(it);
            return;
        }
    }
}

std::vector<Session *> Doctor::getAllSessions() {
    return availableSessions;
}

Doctor::~Doctor() {
    for (Session *session: availableSessions) {
        delete session;
    }

    for (Appointment *appointments: appointment) {
        delete appointments;
    }
}


