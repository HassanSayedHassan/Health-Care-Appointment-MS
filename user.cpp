#include <iostream>
#include <string>
#include <unordered_map>
#include "user.h"
#include "local_data.h"

int User::counter = 0;

User::User(std::string &name, std::string &emailAddress, std::string &password) {
    this->name = name;
    this->emailAddress = emailAddress;
    this->id = ++counter;
    this->password = password;
    createUser();
}

std::string User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    this->name = name;
}

int User::getId() const {
    return id;
}

std::string User::getEmailAddress() const {
    return emailAddress;
}

void User::setEmailAddress(const std::string &email_address) {
    emailAddress = email_address;
}


bool User::createUser() {
    if (users.find(emailAddress) != users.end()) {
        std::cout << "User Already Registered" << std::endl;
        return false;
    }
    if (emailAddress.find("@") != std::string::npos && password.size() >= 8) {
        users[emailAddress] = password;
        std::cout << "Tregistered Successfully" << std::endl;
        return true;
    } else {
        std::cout << "Please enter Valid data" << std::endl;
        return false;
    }

}

bool User::login(std::string &EmailAddress, std::string &password) const {
    if (users.find(EmailAddress) != users.end() && users[EmailAddress] == password) {
        std::cout << "Logged in successfully" << std::endl;
        return true;
    } else {
        std::cout << "Invalid Username or Password" << std::endl;
        return false;
    }
}