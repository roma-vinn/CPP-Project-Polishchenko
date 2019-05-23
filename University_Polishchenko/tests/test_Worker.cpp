//
//  test_Worker.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/21/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "test_Worker.hpp"

int testWorker() {
    try {
        // test constructors
        Worker w1("Worker1", 25);
        Worker w2("Worker2", 28, "TestJob", 4600);
        Worker w3("Worker3", 28, "TestJob", 4600, 10);
        
        // test 'setJob' and 'getJob'
        w1.setJob(w2.getJob());
        
        // test 'getJobName' and correctness of result
        if (w1.getJobName() != "TestJob") {
            throw ;
        }
        
        // test setExperience
        w2.setExperience(10);
        // test 'getExperience' and 'income' and correctness of result
        if (w2.getExperience() != 10 or w2.income() <= 4600) {
            throw ;
        }
        
        // test 'getInfo' and correctness of result
        std::string res = "Worker1, 25 years, TestJob, 0 years seniority, 4600.000000 income, ";
        if (w1.getInfo() != res) {
            throw ;
        }
        
    } catch (...) {
        return -1;
    }
    
    return 0;
}
