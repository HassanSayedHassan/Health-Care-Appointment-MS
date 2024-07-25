#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin : public User {

public:
    Admin(std::string &name, std::string &emailAddress, std::string &password);

    bool addAccount(std::string &name, std::string &emailAddress, std::string &password);

    bool deleteAccount(User &user);


};

#endif