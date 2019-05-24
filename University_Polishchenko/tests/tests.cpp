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
        cout << "WORKER CLASS TEST FAILED!\n";
        success = false;
    } else {
        cout << "Worker class test passed...\n";
    }
    
    if (testRecordBook()) {
        cout << "RECORDBOOK CLASS TEST FAILED!\n";
        success = false;
    } else {
        cout << "RecordBook class test passed...\n";
    }
    
    if (testProfession()) {
        cout << "PROFESSION CLASS TEST FAILED!\n";
        success = false;
    } else {
        cout << "Profession class test passed...\n";
    }
    
    if (testStudent()) {
        cout << "STUDENT CLASS TEST FAILED!\n";
        success = false;
    } else {
        cout << "Student class test passed...\n";
    }
    
    if (testTeacher()) {
        cout << "TEACHER CLASS TEST FAILED!\n";
        success = false;
    } else {
        cout << "Teacher class test passed...\n";
    }
    
    if (!success) {
        return -1;
    } else {
        return 0;
    }
}
