cmake_minimum_required(VERSION 3.28)
project(OOP_Assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_Assignment main.cpp
        Patient.h
        Patient.cpp
        Appointment.cpp
        Appointment.h
        user.h
        Session.h
        user.cpp
        Session.cpp
        doctor.h
        doctor.cpp
        local_data.cpp
        admin.cpp
)
