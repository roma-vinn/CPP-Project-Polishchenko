//
//  Student.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Student.hpp"

//Student::Student(std::string name) : Worker(name)
//{
//}

Student::Student(std::string name, int age) : Worker(name, age)
{
}

//Student::Student(std::string name, std::string job_name,
//                 float base_rate) : Worker(name, job_name, base_rate)
//{
//}

Student::Student(std::string name, int age, std::string job_name,
                 float base_rate) : Worker(name, age, job_name, base_rate)
{
}

Student::Student(std::string name, int age, std::string job_name, float base_rate,
                 RecordBook record_book) : Worker(name, age, job_name, base_rate)
{
    _record_book = record_book;
}

//Student::Student(std::string name, RecordBook record_book) : Worker(name)
//{
//    _record_book = record_book;
//}

Student::Student(std::string name, int age,
                 RecordBook record_book) : Worker(name, age)
{
    _record_book = record_book;
}

void Student::setRecordBook(RecordBook record_book) {
    _record_book = record_book;
}

void Student::updateSubject(std::string sub_name, int grade_point) {
    _record_book.updateSubject(sub_name, grade_point);
}

void Student::showRecordBook() {
    std::cout << _record_book.getRepr() << '\n';
}

float Student::income(){
    return Worker::income() + _get_scholarship();
}

std::string Student::getInfo() {
    return Worker::getInfo() + std::to_string(_get_scholarship())
    + " scholarship (agp - " + std::to_string(getAvgGradePoint()) + "), ";
}

float Student::_get_scholarship() {
    float scholarship = 0.0;
    float avg_gp = _record_book.getAvgGradePoint();
    
    if (avg_gp >= 90) {
        scholarship = 2400.0;
    } else if (avg_gp >= 75) {
        scholarship = 1800.0;
    }
    
    return scholarship;
}
