//
//  Worker.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Worker.hpp"

//Worker::Worker(std::string name) : Human(name)
//{
//}

Worker::Worker(std::string name, int age) : Human(name, age)
{
}

//Worker::Worker(std::string name, std::string job_name,
//               float base_rate) : Human(name)
//{
//    _job.setProfName(job_name);
//    _job.setBaseRate(base_rate);
//}

Worker::Worker(std::string name, int age,
               std::string job_name, float base_rate) : Human(name, age)
{
    _job.setProfName(job_name);
    _job.setBaseRate(base_rate);
}

//Worker::Worker(std::string name, int age,
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

std::string Worker::getInfo() {
    return Human::getInfo() + _job.getProfName() + ", "
    + std::to_string(_experience) + " years seniority, "
    + std::to_string(income()) + ", ";
}
