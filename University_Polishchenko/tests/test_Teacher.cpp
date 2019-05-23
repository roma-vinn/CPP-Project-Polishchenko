//
//  test_Teacher.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/22/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "test_Teacher.hpp"

int testTeacher() {
    try {
        std::map<std::string, int> records {{"Math", 100}, {"History", 80}};
        RecordBook rb(records);
        
        Student s1("Student1", 20, rb);
        
        rb.updateSubject("History", 90);
        Student s2("Student2", 22, rb);
        
        rb.updateSubject("Biology", 50);
        Student s3("Student3", 21, rb);
        
        // test constructors
        Teacher t1("Teacher1", 28);
        Teacher t2("Teacher2", 36, "Master");
        
        // test 'getInfo' and correctness of results
        std::string res1 = "Teacher1, 28 years, Teacher, 0 years seniority, 6000.000000 income, None degree, ";
        std::string res2 = "Teacher2, 36 years, Teacher, 0 years seniority, 7200.000488 income, Master degree, ";
        if (t1.getInfo() != res1 || t2.getInfo() != res2) {
            throw ;
        }
        
        // test 'setDegree' and 'getDegree' and correctness of result
        t1.setDegree(t2.getDegree());
        if (t1.getDegree() != "Master") {
            throw ;
        }
        
        // test 'income' and correctness of result
//        std::cout << t1.income();
        if (t1.income() - 7200 > 0.001) {
            throw ;
        }
        
        // test 'addStudent'
        t1.addStudent(s1);
        t1.addStudent(s2);
        t2.addStudent(s1);
        t2.addStudent(s2);
        t2.addStudent(s3);
        
        // test 'removeStudent'
        t2.removeStudent("Student2");
        
        // test 'getAvgGradePoint' and correctness of results
        if (t1.getAvgGradePoint() != 92.5 || t2.getAvgGradePoint() != 85) {
            throw ;
        }
    
        
    } catch (...) {
        return -1;
    }
    
    return 0;
}
