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

using namespace std;

extern bool LOGGING;
extern string logs;

// ==================== Worker ==================== //

/*
 Class that implements Worker entity. Inherited from Human.
 Additionally contains information about job name and base rate (salary).
 */
class Worker: public Human {
public:
    /* create worker with given name and age
     @param name: worker's name
     @param age: worker's age
     */
    Worker(string name, int age);
    
    /* create worker with given name, age, job name and base rate
     @param name: worker's name
     @param age: worker's age
     @param job_name: worker's job name
     @param base_rate: worker's base rate (salary)
     */
    Worker(string name, int age, string job_name, float base_rate);
    
    /* create worker with given name, age, job name, base rate and seniority
     @param name: worker's name
     @param age: worker's age
     @param job_name: worker's job name
     @param base_rate: worker's base rate (salary)
     @param seniority: worker's seniority (years of work / experience)
     */
    Worker(string name, int age, string job_name,
           float base_rate, int seniority);
    
    /* default destructor
     */
    ~Worker() {};
    
    /* getter for the job name
     */
    string getJobName() { return _job.getProfName(); };
    
    /* setter for the job name
     @param name: new job name
     */
    void setJob(Profession profession);
    
    /* getter for the job as Profession class object
     */
    Profession getJob() { return _job; };
    
    /* setter for the seniority
     @param name: years of work (seniority / experience)
     */
    void setExperience(int years) { _experience = years; };
    
    /* getter for the seniority
     */
    int getExperience() { return _experience; };
    
    /* virtual method that return the income of the worker
     income = base rate * seniority coefficient
     */
    virtual float income();
    
    /* virtual method that return string
     representation of info about this worker
     in format: "Name, age, job name, N years seniority, X income, "
     */
    virtual string getInfo();
private:
    /* field that contains workers seniority years
     */
    int _experience = 0;

    /* field that contains workers job
     */
    Profession _job{"None", 0};
};

#endif /* Worker_hpp */
