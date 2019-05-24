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
    _job.setProfName(job_name);
    _job.setBaseRate(base_rate);
}

Worker::Worker(string name, int age, string job_name,
               float base_rate, int seniority) : Human(name, age)
{
    _job.setProfName(job_name);
    _job.setBaseRate(base_rate);
    setExperience(seniority);
}

//Worker::Worker(string name, int age,
//               Profession prof): Human(name, age) {
//    _job = prof;
//}

void Worker::setJob(Profession profession) {
    _job = profession;
}

/*
 income = 'job base rate' * 'experience coefficient',
 where 'experience coefficient' counts
 as +5% for every 5 years of work.
 */
float Worker::income() {
    return _job.getBaseRate() * (1 + static_cast<int>(_experience / 5) * 0.05);
}

string Worker::getInfo() {
    return Human::getInfo() + _job.getProfName() + ", "
    + to_string(_experience) + " years seniority, "
    + to_string(income()) + " income, ";
}
