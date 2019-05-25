//
//  Teacher.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "Teacher.hpp"

// multiplying salary corresponding to the degree
const map<string, float> Teacher::_degreeFactor {
    {"None", 1.0},
    {"Bachelor", 1.1},
    {"Master", 1.2},
    {"Doctor", 1.4}
};

// teachers' salary
const float Teacher::_salary = 6000;

//Teacher::Teacher(string name) : Worker(name) {
//    setJob("Teacher", _salary);
//}

Teacher::Teacher(string name, int age) : Worker(name, age) {
    // logging
    if (LOGGING) {
        logs += "Called Teacher constructor with params: <";
        logs += name + ", " + to_string(age) + ">\n";
    }
    
    setJob(Profession("Teacher", _salary));
    if (LOGGING) {
        cout << "Oooooooooooooooo.\n";
    }
}

//Teacher::Teacher(string name, string degree) : Worker(name) {
//    setJob("Teacher", _salary);
//    setDegree(degree);
//}

Teacher::Teacher(string name, int age,
                 string degree, int seniority) : Worker(name, age) {
    // logging
    if (LOGGING) {
        logs += "Called Teacher constructor with params: <";
        logs += name + ", " + to_string(age) + degree
        + to_string(seniority) + ">\n";
    }
    
    setJob(Profession("Teacher", _salary));
    setDegree(degree);
    setExperience(seniority);
}

void Teacher::setDegree(string degree) {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'setDegree' with params: <";
        logs += degree + ">\n";
    }
    
    bool found = false;
    for (map<string, float>::const_iterator it = _degreeFactor.begin(),
         end = _degreeFactor.end()
         ; it != end; ++it) {
        if (degree == it->first) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Incorrect degree: " << degree <<
        ". Should be one of the next one:";
        for (map<string, float>::const_iterator it = _degreeFactor.begin(),
             end = _degreeFactor.end()
             ; it != end; ++it) {
            cout << it->first << ' ';
        }
        cout << endl;
    } else {
        _degree = degree;
    }
}

float Teacher::income() {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'income'\n";
    }
    
    float coef = _degreeFactor.at(_degree);
    float inc = Worker::income();
    return inc * coef;
}

void Teacher::addStudent(Student& student) {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'addStudent' with params: <";
        logs += "Student(" + student.getName() + ")>\n";
    }
    
    _students.push_back(&student);
    student.updateTeacherName(getName());
}

void Teacher::addStudent(Student* student) {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'addStudent' with params: <";
        logs += "Student(" + student->getName() + ")>\n";
    }
    
    _students.push_back(student);
    (*student).updateTeacherName(getName());
}

void Teacher::removeStudent(string st_name) {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'removeStudent' with params: <";
        logs += st_name + ">\n";
    }
    
    for (vector<Student*>::const_iterator it = _students.begin(),
         end = _students.end();
         it != end; ++it) {
        if ((*it)->getName() == st_name) {
            _students.erase(it);
            break;
        }
    }
}

void Teacher::showStudents() {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'showStudents'\n";
    }
    
    cout << "Students of " << getName() << ":\n";
    for (vector<Student*>::const_iterator it = _students.begin(),
         end = _students.end();
         it != end; ++it) {
        cout << (*it)->getInfo() << endl;
    }
}

float Teacher::getAvgGradePoint() {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'getAvgGradePoint'\n";
    }
    
    float avg_gp = 0.0, sum = 0.0;
    size_t count;
    if (_students.size() > 0) {
        for (count = 0; count<_students.size(); ++count) {
            sum += _students[count]->getAvgGradePoint();
        }
        avg_gp = sum / count;
    }
    
    return avg_gp;
}

string Teacher::getInfo() {
    // logging
    if (LOGGING) {
        logs += "Called Teacher method 'getInfo'\n";
    }
    
    return Worker::getInfo() + _degree + " degree, ";
}

