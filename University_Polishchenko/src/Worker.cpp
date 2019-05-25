//
//  Worker.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Worker.hpp"

//Worker::Worker(string name) : Human(name)
//{
//}

Worker::Worker(string name, int age) : Human(name, age)
{
    // logging
    if (LOGGING) {
        logs += "Called Worker constructor with params: <";
        logs += name + ", " + to_string(age) + ">\n";
    }
}

//Worker::Worker(string name, string job_name,
//               float base_rate) : Human(name)
//{
//    _job.setProfName(job_name);
//    _job.setBaseRate(base_rate);
//}

Worker::Worker(string name, int age,
               string job_name, float base_rate) : Human(name, age)
{
    // logging
    if (LOGGING) {
        logs += "Called Worker constructor with params: <";
        logs += name + ", " + to_string(age) + job_name
        + to_string(base_rate) + ">\n";
    }
    
    _job.setProfName(job_name);
    _job.setBaseRate(base_rate);
}

Worker::Worker(string name, int age, string job_name,
               float base_rate, int seniority) : Human(name, age)
{
    // logging
    if (LOGGING) {
        logs += "Called Worker constructor with params: <";
        logs += name + ", " + to_string(age) + job_name
        + to_string(base_rate) + ">\n";
    }
    
    _job.setProfName(job_name);
    _job.setBaseRate(base_rate);
    setExperience(seniority);
}

//Worker::Worker(string name, int age,
//               Profession prof): Human(name, age) {
//    _job = prof;
//}

void Worker::setJob(Profession profession) {
    // logging
    if (LOGGING) {
        logs += "Called Worker method 'setJob' with params: <";
        logs += "Profession(" + profession.getProfName() + ", " +
        to_string(profession.getBaseRate())+ ")>\n";
    }
    
    _job = profession;
}

/*
 income = 'job base rate' * 'experience coefficient',
 where 'experience coefficient' counts
 as +5% for every 5 years of work.
 */
float Worker::income() {
    // logging
    if (LOGGING) {
        logs += "Called Worker method 'income'\n";
    }
    
    return _job.getBaseRate() * (1 + static_cast<int>(_experience / 5) * 0.05);
}

string Worker::getInfo() {
    // logging
    if (LOGGING) {
        logs += "Called Worker method 'getInfo'\n";
    }
    
    return Human::getInfo() + _job.getProfName() + ", "
    + to_string(_experience) + " years seniority, "
    + to_string(income()) + " income, ";
}
