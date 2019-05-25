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

class Teacher : public Worker {
public:
//    Teacher(string name);
    Teacher(string name, int age);
//    Teacher(string name, string degree);
    Teacher(string name, int age, string degree, int seniority);

    ~Teacher() {};
    void setDegree(string degree);
    string getDegree() { return _degree; };

    float income();
    
    void addStudent(Student& student);
    void addStudent(Student* student);
    void removeStudent(string st_name);
    void showStudents();
    
    float getAvgGradePoint();
    
    string getInfo();
private:
    string _degree = "None";
    vector<Student*> _students;
    static const map<string, float> _degreeFactor;
    static const float _salary;
};

#endif /* Teacher_hpp */
