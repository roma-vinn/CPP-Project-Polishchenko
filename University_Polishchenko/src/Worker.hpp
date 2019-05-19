//
//  Worker.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef Worker_hpp
#define Worker_hpp

#include <iostream>
#include <string>
#include "Profession.hpp"
#include "Human.hpp"

class Worker: public Human {
public:
    Worker(std::string name);
    Worker(std::string name, int age);
    Worker(std::string name, std::string job_name, float base_rate);
    Worker(std::string name, int age, std::string job_name, float base_rate);
    ~Worker() {};
    
    std::string getJobName() { return _job.getProfName(); };
    void setJob(std::string job_name, float base_rate);
    void setExperience(int years) { _experience = years; };
    
    virtual float income();
    
    virtual std::string getInfo();
private:
    // years of work
    int _experience = 0;

    // basic profession
    Profession _job{"None", 0};
};

#endif /* Worker_hpp */
