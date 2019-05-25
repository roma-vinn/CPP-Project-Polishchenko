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

extern bool LOGGING;
extern string logs;

// ==================== Student ==================== //

/*
 Class that implements Student entity. Inherited from Worker.
 Additionally contains information about record book and teacher name.
 */
class Student : public Worker {
public:
    /* create student with given name and age
     @param name: student's name
     @param age: student's age
     */
    Student(string name, int age);
    
    /* create student with given name, age, job name and base rate
     @param name: student's name
     @param age: student's age
     @param job_name: student's job name
     @param base_rate: student's base rate (salary)
     */
    Student(string name, int age, string job_name, float base_rate);
    
    /* create student with given name, age, job name,
     base rate, teacher name and record book
     @param name: student's name
     @param age: student's age
     @param job_name: student's job name
     @param base_rate: student's base rate (salary)
     @param teacher_name: name of the teacher
     @param record_book: RecordBook class obj
     */
    Student(string name, int age, string job_name,
            float base_rate, string teacher_name, RecordBook record_book);
    
    /* create student with given name, age, teacher name and record book
     @param name: student's name
     @param age: student's age
     @param teacher_name: name of the teacher
     @param record_book: RecordBook class obj
     */
    Student(string name, int age, string teacher_name, RecordBook record_book);
    
    /* default destructor
     */
    ~Student() {};
    
    /* getter for the record book
     */
    RecordBook getRecordBook() { return _record_book; };
    
    /* setter for the record book
     */
    void setRecordBook(RecordBook record_book);
    
    /* method for updating grade point for existing subject
     (or adding a new subject)
     @param sub_name: name of the subject
     @param grade_point: grade point for this subject
     */
    void updateSubject(string sub_name, int grade_point);
    
    /* method for getting representation of record book to
     print it in the console. Printing string with each subject
     from new line and avarage grade point in the end.
     */
    void showRecordBook();
    
    /* getter for the avarage grade point
     */
    float getAvgGradePoint() { return _record_book.getAvgGradePoint(); };
    
    /* method that return the income of the student
     income = income (as worker) + scholarship
     */
    float income();
    
    /* method for updating teacher name
     @param new_teacher: new teacher's name
     */
    void updateTeacherName(string new_teacher);

    /* method that return string
     representation of info about this student
     in format: "Name, age, job name, N years seniority, X income, Y scolarship (agp - Z), teacher_name's student, "
     */
    string getInfo();
    
private:
    /* field that contains student's record book
     */
    RecordBook _record_book;
    
    /* hidden method for getting scholarship in depence on avarage grade point
     */
    float _get_scholarship();
    
    /* field that contains student's teacher name
     */
    string _teacher_name = "";
};

#endif /* Student_hpp */
