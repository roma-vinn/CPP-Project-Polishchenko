//
//  main.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include <iostream>
#include "tests/tests.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    if (tests()) {
        cout << "Something went wrong.\n";
    } else {
        cout << "Everything OK.\n";
    }
    
//    // Teacher test
//    Teacher t1("Teacher1", 28);
//    Teacher t2("Teacher2", 35, "Master");
//    Teacher t3("Teacher3", 35, "Master");
//    t3.setExperience(12);
//
//    cout << t1.getInfo() << endl;
//    cout << t2.getInfo() << endl;
//    cout << t3.getInfo() << endl;
//
//    // Student test
//    RecordBook rb;
//    rb.updateSubject("Math", 95);
//    rb.updateSubject("History", 85);
//    rb.updateSubject("English", 89);
//
//    Student s1("Student1", 18);
//    Student s2("Student2", 20, "Tutor", 1600);
//    Student s3("Student3", 21, rb);
//    rb.updateSubject("English", 90);
//    Student s4("Student4", 22, "Tutor", 1300, rb);
//
//    cout << s1.getInfo() << endl;
//    cout << s2.getInfo() << endl;
//    cout << s3.getInfo() << endl;
//    cout << s4.getInfo() << endl;
//
//    // Students list test
//
//    t2.addStudent(s1);
//    t2.addStudent(s2);
//    t2.addStudent(s3);
//    t2.addStudent(s4);
//
//    t2.showStudents();
//    cout << "Avarage grade point - " << t2.getAvgGradePoint() << endl;
    
    return 0;
}
