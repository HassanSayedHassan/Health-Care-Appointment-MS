#include "Patient.h"
#include "local_data.h"

bool Patient::manageProfile(std::string Name, std::string EmailAddress) {
    if (!EmailAddress.find('@')) {
        std::cout << "Please enter a valid Email Address" << std::endl;
        return false;
    }
    if (Name.size() < 2) {
        std::cout << "Please enter a valid Name" << std::endl;
        return false;
    } else {
        setName(Name);
        setEmailAddress(EmailAddress);
        std::cout << "Updated Successfully" << std::endl;
        return true;
    }
}

bool Patient::bookAppointment(int doctorId, int sessionId) {
    Doctor *doctor = doctors[doctorId];
    if (doctor->isFreeSession(sessionId)) {
        Appointment *resrvedAppointment = new Appointment(getId(), doctorId, sessionId);
        this->appointments.push_back(resrvedAppointment);
        doctor->addAppointment(resrvedAppointment);
        std::cout << "Appointment Booked successfully" << std::endl;
        return true;
    } else {
        std::cout << "All Appointments are reserved" << std::endl;
        return false;
    }
}

bool Patient::cancelAppointment(int doctorId, int sessionId) {
    Doctor *doctor = doctors[doctorId];
    doctor->removeAppointment(sessionId);
    for (auto it = appointments.begin(); it != appointments.end(); ++it) {
        if ((*it)->getSessionId() == sessionId) {
            Appointment *temp = *it;
            appointments.erase(it);
            delete temp;
            return true;
        }
    }
    return false;
}

std::vector<Appointment *> Patient::viewBookedAppointments() {
    return appointments;
}

std::vector<Session *> Patient::viewAvailableSessions(int doctorId) {
    Doctor *doctor = doctors[doctorId];
    return doctor->getAllSessions();
}

std::string Patient::viewMedicalRecord() {
    return medicalRecord;
}

void Patient::set_medical_record(const std::string &medical_record) {
    medicalRecord = medical_record;
}




