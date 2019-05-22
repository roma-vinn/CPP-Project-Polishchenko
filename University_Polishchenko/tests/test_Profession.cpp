//
//  test_Profession.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/22/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "test_Profession.hpp"

int testProfession() {
    try {
        // test constructors
        Profession pr1("TestJob", 12000);
        
        // test 'getProfName' and correctness of result
        if (pr1.getProfName() != "TestJob") {
            throw ;
        }
        
        // test 'getBaseRate' and correctness of result
        if (pr1.getBaseRate() != 12000) {
            throw ;
        }
        
        // test 'setProfName' and correctness of result
        pr1.setProfName("AnotherJob");
        if (pr1.getProfName() != "AnotherJob") {
            throw ;
        }
        
        // test 'setBaseRate' and correctness of result
        pr1.setBaseRate(6000);
        if (pr1.getBaseRate() != 6000) {
            throw ;
        }
        
    } catch (...) {
        return -1;
    }
    
    return 0;
}
