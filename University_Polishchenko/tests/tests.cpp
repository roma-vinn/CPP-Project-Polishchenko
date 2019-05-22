//
//  tests.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/22/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "tests.hpp"

int tests() {
    bool success = true;
    
    if (testWorker()) {
        std::cout << "WORKER CLASS TEST FAILED!\n";
        success = false;
    } else {
        std::cout << "Worker class test passed...\n";
    }
    
    if (testRecordBook()) {
        std::cout << "RECORDBOOK CLASS TEST FAILED!\n";
        success = false;
    } else {
        std::cout << "RecordBook class test passed...\n";
    }
    
    if (testProfession()) {
        std::cout << "PROFESSION CLASS TEST FAILED!\n";
        success = false;
    } else {
        std::cout << "Profession class test passed...\n";
    }
    
    if (testStudent()) {
        std::cout << "STUDENT CLASS TEST FAILED!\n";
        success = false;
    } else {
        std::cout << "Student class test passed...\n";
    }
    
    if (!success) {
        return -1;
    } else {
        return 0;
    }
}
