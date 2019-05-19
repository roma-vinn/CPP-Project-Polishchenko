//
//  Profession.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Profession.hpp"

Profession::Profession(std::string prof_name, int base_rate)
:_prof_name(prof_name),
_base_rate(base_rate)
{
}

void Profession::setProfName(std::string prof_name) {
    // in case of calling with empty string
    if (prof_name.length() == 0) {
        std::cout << "Invalid profession name.\n";
    } else {
        _prof_name = prof_name;
    }
}

void Profession::setBaseRate(int base_rate) {
    // in case of calling with incorrect base_rate
    if (base_rate < 0) {
        std::cout << "Invalid base rate: " << base_rate <<
        ". Must be not less than 0.\n";
    } else {
        _base_rate = base_rate;
    }
}
