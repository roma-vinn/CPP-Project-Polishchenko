//
//  test_Student.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/22/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "test_Student.hpp"

int testStudent() {
    try {
        map<string, int> records {{"Math", 100}, {"History", 80}};
        RecordBook rb(records);
        // test constructors
        Student s1("Student1", 19);
        Student s2("Student2", 21, "TestJob1", 2500);
        Student s3("Student3", 23, "TestJob2", 2400, "Georgiy Shevchenko", rb);
        Student s4("Student4", 20, "Oksana Bezushchak", rb);
        
        // test 'getAvgGradePoint' and correctness of result
        if (s1.getAvgGradePoint() != 0 || s3.getAvgGradePoint() != 90) {
            throw ;
        }
        
        // test 'income' and correctness of result
        if (s1.income() != 0 || s2.income() != 2500 ||
            s3.income() != 4800 || s4.income() != 2400) {
            throw ;
        }
        
        // test 'setRecordBook' and 'getRecordBook'
        s1.setRecordBook(s4.getRecordBook());
        
        // test 'updateSubject' and correctness of result
        s1.updateSubject("History", 100);
        if (s1.getAvgGradePoint() != 100) {
            throw ;
        }
        
        string res1 = "Student1, 19 years, None, 0 years seniority, 2400.000000 income, 2400.000000 scholarship (agp - 100.000000), ",
        res4 = "Student4, 20 years, None, 0 years seniority, 2400.000000 income, 2400.000000 scholarship (agp - 90.000000), Oksana Bezushchak's student, ";
        
        // test 'getInfo' and correctness of results
        if (s1.getInfo() != res1 || s4.getInfo() != res4) {
            throw ;
        }
        
    } catch (...) {
        return -1;
    }
    
    return 0;
}
