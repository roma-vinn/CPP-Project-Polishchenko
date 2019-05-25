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

extern bool LOGGING;
extern string logs;

// ==================== Profession ==================== //

/*
 Class that implements Profession for Workers.
 Contains information about job name and base rate (a.k.a. base salary).
 */
class Profession {
public:
    /* create profession with given name and base rate
     @param prof_name: names of the job
     @param base_rate: base rate (base salary)
     */
    Profession(string prof_name, float base_rate);
    
    /* default destructor
     */
    ~Profession() {};
    
    /* getter for job name
     */
    string getProfName() { return _prof_name; };
    
    /* getter for base rate
     */
    float getBaseRate() { return _base_rate; };
    
    /* setter for job name
     */
    void setProfName(string prof_name);
    
    /* setter for base rate
     */
    void setBaseRate(float base_rate);
private:
    // name (title) of the profession
    string _prof_name = "";
    
    // minimal income for this proffesion per month
    float _base_rate = 0;
};

#endif /* Profession_hpp */
