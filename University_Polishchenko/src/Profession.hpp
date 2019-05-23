//
//  Profession.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef Profession_hpp
#define Profession_hpp

#include <iostream>
#include <string>

/*
 TODO: write short description
 */
class Profession {
public:
    Profession(std::string prof_name, float base_rate);
    ~Profession() {};
    std::string getProfName() { return _prof_name; };
    float getBaseRate() { return _base_rate; };
    void setProfName(std::string prof_name);
    void setBaseRate(float base_rate);
private:
    // name (title) of the profession
    std::string _prof_name = "";
    
    // minimal income for this proffesion per month
    float _base_rate = 0;
};

#endif /* Profession_hpp */
