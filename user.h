#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
    std::string name;
    int id;
    static int counter;
    std::string emailAddress;
    std::string password;


public:
    User(std::string &name, std::string &emailAddress, std::string &password);

    /* getters */
    std::string getName() const;

    int getId() const;

    std::string getEmailAddress() const;

    /* setters */
    void setName(const std::string &name);

    void setEmailAddress(const std::string &email_address);

    /* methods */
    bool createUser();

    bool login(std::string &, std::string &) const;

};

#endif