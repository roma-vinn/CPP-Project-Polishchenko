//
//  Teacher.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef Teacher_hpp
#define Teacher_hpp

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Worker.hpp"
#include "Student.hpp"

using namespace std;

extern bool LOGGING;
extern string logs;

// ==================== Teacher ==================== //

/*
 Class that implements Teacher entity. Inherited from Worker.
 Additionally contains information about degree and list of its student.
 */
class Teacher : public Worker {
public:
    /* create teacher with given name and age
     @param name: teacher's name
     @param age: teacher's age
     */
    Teacher(string name, int age);
    
    /* create teacher with given name, age, degree and seniority
     @param name: teacher's name
     @param age: teacher's age
     @param degree: teacher's degree [Bachelor, Master, Doctor or None]
     @param seniority: teacher's seniority (years of work / experience)
     */
    Teacher(string name, int age, string degree, int seniority);
    
    /* default destructor
     */
    ~Teacher() {};
    
    /* setter for the degree
     @param degree: new degree
     */
    void setDegree(string degree);
    
    /* getter for the degree
     */
    string getDegree() { return _degree; };

    /* method that return the income of the teacher
     income = base rate (6000) * seniority coefficient * degree coefficient
     */
    float income();
    
    /* method for adding student to the teacher by the reference
     @param student: reference on the Student obj
     */
    void addStudent(Student& student);
    
    /* method for adding student to the teacher by the pointer
     @param student: pointer on the Student obj
     */
    void addStudent(Student* student);
    
    /* method for deleting student by the name
     @param st_name: name of the student to delete
     */
    void removeStudent(string st_name);
    
    /* method that prints info about this teacher's students
     in format: "Students of _teacher_name:
                 Info about Student 1
                 Info about Student 2
                 ..."
     */
    void showStudents();
    
    /* method to get avarage grade point of all students of this teacher
     */
    float getAvgGradePoint();
    
    /* virtual method that return string
     representation of info about this teacher
     in format: "Name, age, Teacher, N years seniority, X income, D degree, "
     */
    string getInfo();
private:
    /* field that contains teacher's degree
     */
    string _degree = "None";
    
    /* field that contains list of students
     */
    vector<Student*> _students;
    
    /* const field that contains degree coefficients
     */
    static const map<string, float> _degreeFactor;
    
    /* const field that contains basic teachers' salary
     */
    static const float _salary;
};

#endif /* Teacher_hpp */
