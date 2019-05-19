//
//  Human.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Human.hpp"

Human::Human(std::string name, int age)
{
    if (name.length() == 0) {
        std::cout << "Name can`t empty string.\n";
    } else if (age < 0) {
        std::cout << "Incorrect age: " << age << ". Should be not less 0.\n";
    } else {
        _name = name;
        _age = age;
    }
}

Human::Human(std::string name)
{
    if (name.length() == 0) {
        std::cout << "Name can`t empty string.\n";
    } else {
        _name = name;
    }
}

void Human::setName(std::string name) {
    // in case of calling with empty string
    if (name.length() == 0) {
        std::cout << "Invalid name.\n";
    } else {
        _name = name;
    }
}

void Human::setAge(int age) {
    // in case of calling with incorrect age
    if (age < 0) {
        std::cout << "Invalid age: " << age <<
        ". Must be not less than 0.\n";
    } else {
        _age = age;
    }
}

std::string Human::getInfo() {
    return _name + ", " + std::to_string(_age) + " years, ";
}
