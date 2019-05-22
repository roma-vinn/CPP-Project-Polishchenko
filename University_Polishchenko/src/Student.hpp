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

class Student : public Worker {
public:
//    Student(std::string name);
    Student(std::string name, int age);
//    Student(std::string name, std::string job_name, float base_rate);
    Student(std::string name, int age, std::string job_name, float base_rate);
    Student(std::string name, int age, std::string job_name,
            float base_rate, RecordBook record_book);
//    Student(std::string name, RecordBook record_book);
    Student(std::string name, int age, RecordBook record_book);
    
    RecordBook getRecordBook() { return _record_book; };
    void setRecordBook(RecordBook record_book);
    
    void updateSubject(std::string sub_name, int grade_point);
    void showRecordBook();
    float getAvgGradePoint() { return _record_book.getAvgGradePoint(); };
    float income();

    std::string getInfo();
    
private:
    RecordBook _record_book;
    float _get_scholarship();
};

#endif /* Student_hpp */
