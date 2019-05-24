//
//  Student.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include "Worker.hpp"
#include "RecordBook.hpp"

using namespace std;

class Student : public Worker {
public:
//    Student(string name);
    Student(string name, int age);
//    Student(string name, string job_name, float base_rate);
    Student(string name, int age, string job_name, float base_rate);
    Student(string name, int age, string job_name,
            float base_rate, string teacher_name, RecordBook record_book);
//    Student(string name, RecordBook record_book);
    Student(string name, int age, string teacher_name, RecordBook record_book);
    
    RecordBook getRecordBook() { return _record_book; };
    void setRecordBook(RecordBook record_book);
    
    void updateSubject(string sub_name, int grade_point);
    void showRecordBook();
    float getAvgGradePoint() { return _record_book.getAvgGradePoint(); };
    float income();
    void updateTeacherName(string new_teacher);

    string getInfo();
    
private:
    RecordBook _record_book;
    float _get_scholarship();
    string _teacher_name = "";
};

#endif /* Student_hpp */
