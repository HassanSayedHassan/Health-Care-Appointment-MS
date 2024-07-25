#ifndef LOCAL_DATA_H
#define LOCAL_DATA_H

#include <string>
#include <unordered_map>
#include "doctor.h"
#include <algorithm>

extern std::unordered_map<std::string, std::string> users;
extern std::unordered_map<int, Doctor *> doctors;

#endif
