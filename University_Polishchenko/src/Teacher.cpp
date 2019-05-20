//
//  Teacher.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Teacher.hpp"

const std::map<std::string, float> Teacher::_degreeFactor {
    {"None", 1.0},
    {"Bachelor", 1.1},
    {"Master", 1.2},
    {"Doctor", 1.4}
};

const float Teacher::_salary = 6000;

Teacher::Teacher(std::string name) : Worker(name) {
    setJob("Teacher", _salary);
}

Teacher::Teacher(std::string name, int age) : Worker(name, age) {
    setJob("Teacher", _salary);
}

Teacher::Teacher(std::string name, std::string degree) : Worker(name) {
    setJob("Teacher", _salary);
    setDegree(degree);
}

Teacher::Teacher(std::string name, int age,
                 std::string degree) : Worker(name, age) {
    setJob("Teacher", _salary);
    setDegree(degree);
}

void Teacher::setDegree(std::string degree) {
    bool found = false;
    for (std::map<std::string, float>::const_iterator it = _degreeFactor.begin(),
         end = _degreeFactor.end()
         ; it != end; ++it) {
        if (degree == it->first) {
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Incorrect degree: " << degree <<
        ". Should be one of the next one:";
        for (std::map<std::string, float>::const_iterator it = _degreeFactor.begin(),
             end = _degreeFactor.end()
             ; it != end; ++it) {
            std::cout << it->first << ' ';
        }
        std::cout << std::endl;
    } else {
        _degree = degree;
    }
}

float Teacher::income() {
    float coef = _degreeFactor.at(_degree);
    float inc = Worker::income();
    return inc * coef;
}

//void addStudent(Student student);
//void removeStudent(std::string st_name);
//void showStudentList();
//
//float getAvgGradePoint();

void Teacher::addStudent(Student& student) {
    _students.push_back(&student);
}

void Teacher::removeStudent(std::string st_name) {
    for (std::vector<Student*>::const_iterator it = _students.begin(),
         end = _students.end();
         it != end; ++it) {
        if ((*it)->getName() == st_name) {
            _students.erase(it);
            break;
        }
    }
}

void Teacher::showStudents() {
    std::cout << "Students:\n";
    for (std::vector<Student*>::const_iterator it = _students.begin(),
         end = _students.end();
         it != end; ++it) {
        std::cout << (*it)->getInfo() << std::endl;
    }
}

float Teacher::getAvgGradePoint() {
    float avg_gp = 0.0, sum = 0.0, count = 0.0;
    if (_students.size() > 0) {
        for (size_t i = 0; i<_students.size(); ++i) {
            sum += _students[i]->getAvgGradePoint();
        }
        
        avg_gp = sum / count;
    }
    
    return avg_gp;
}

std::string Teacher::getInfo() {
    return Worker::getInfo() + _degree + " degree, ";
}

