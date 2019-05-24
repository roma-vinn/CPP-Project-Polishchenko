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

using namespace std;


class Profession {
public:
    Profession(string prof_name, float base_rate);
    ~Profession() {};
    string getProfName() { return _prof_name; };
    float getBaseRate() { return _base_rate; };
    void setProfName(string prof_name);
    void setBaseRate(float base_rate);
private:
    // name (title) of the profession
    string _prof_name = "";
    
    // minimal income for this proffesion per month
    float _base_rate = 0;
};

#endif /* Profession_hpp */
