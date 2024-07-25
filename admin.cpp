#include "admin.h"
#include "local_data.h"

Admin::Admin(std::string &name, std::string &emailAddress, std::string &password) :
        User(name, emailAddress, password) {

}

bool Admin::addAccount(std::string &name, std::string &emailAddress, std::string &password) {
    auto user = User(name, emailAddress, password);
    return true;
}

bool Admin::deleteAccount(User &user) {
    users.erase(user.getEmailAddress());
    return true;
}
