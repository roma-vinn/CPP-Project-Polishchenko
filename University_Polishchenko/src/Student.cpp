//
//  Student.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Student.hpp"

//Student::Student(string name) : Worker(name)
//{
//}

Student::Student(string name, int age) :
Worker(name, age)
{
    // logging
    if (LOGGING) {
        logs += "Called Student constructor with params: <";
        logs += name + ", " + to_string(age) + ">\n";
    }
}

//Student::Student(string name, string job_name,
//                 float base_rate) : Worker(name, job_name, base_rate)
//{
//}

Student::Student(string name, int age, string job_name,
                 float base_rate) :
Worker(name, age, job_name, base_rate)
{
    // logging
    if (LOGGING) {
        logs += "Called Student constructor with params: <";
        logs += name + ", " + to_string(age) +
        job_name + to_string(base_rate) + ">\n";
    }
}

Student::Student(string name, int age, string job_name, float base_rate,
                 string teacher_name, RecordBook record_book) :
Worker(name, age, job_name, base_rate)
{
    // logging
    if (LOGGING) {
        logs += "Called Student constructor with params: <";
        logs += name + ", " + to_string(age) +
        job_name + to_string(base_rate) + teacher_name +
        "RecordBook(" + record_book.getBook() + ")>\n";
    }
    
    _record_book = record_book;
    _teacher_name = teacher_name;
}

//Student::Student(string name, RecordBook record_book) : Worker(name)
//{
//    _record_book = record_book;
//}

Student::Student(string name, int age,
                 string teacher_name, RecordBook record_book) :
Worker(name, age)
{
    // logging
    if (LOGGING) {
        logs += "Called Student constructor with params: <";
        logs += name + ", " + to_string(age) +
        teacher_name + "RecordBook(" + record_book.getBook() + ")>\n";
    }
    
    _record_book = record_book;
    _teacher_name = teacher_name;
}

void Student::setRecordBook(RecordBook record_book) {
    // logging
    if (LOGGING) {
        logs += "Called Student method 'setRecordBook' with params: <";
        logs += "RecordBook(" + record_book.getBook() + ")>\n";
    }
    
    _record_book = record_book;
}

void Student::updateSubject(string sub_name, int grade_point) {
    // logging
    if (LOGGING) {
        logs += "Called Student method 'updateSubject' with params: <";
        logs += sub_name + ", " + to_string(grade_point) + ">\n";
    }
    
    _record_book.updateSubject(sub_name, grade_point);
}

void Student::showRecordBook() {
    // logging
    if (LOGGING) {
        logs += "Called Student method 'showRecordBook'\n";
    }
    
    cout << _record_book.getRepr() << '\n';
}

float Student::income(){
    // logging
    if (LOGGING) {
        logs += "Called Student method 'income'\n";
    }
    
    return Worker::income() + _get_scholarship();
}

void Student::updateTeacherName(string new_teacher) {
    // logging
    if (LOGGING) {
        logs += "Called Student method 'updateTeacherName' with params: <";
        logs += new_teacher + ">\n";
    }
    
    _teacher_name = new_teacher;
}


string Student::getInfo() {
    // logging
    if (LOGGING) {
        logs += "Called Student method 'getInfo'\n";
    }
    
    string output = Worker::getInfo() + to_string(_get_scholarship())
    + " scholarship (agp - " + to_string(getAvgGradePoint()) + "), ";
   
    if (_teacher_name.length() > 0) {
        output += _teacher_name + "'s student, ";
    }
    
    return output;
}

float Student::_get_scholarship() {
    // logging
    if (LOGGING) {
        logs += "Called Student method '_get_scholarship'\n";
    }
    
    float scholarship = 0.0;
    float avg_gp = _record_book.getAvgGradePoint();
    
    if (avg_gp >= 90) {
        scholarship = 2400.0;
    } else if (avg_gp >= 75) {
        scholarship = 1800.0;
    }
    
    return scholarship;
}
