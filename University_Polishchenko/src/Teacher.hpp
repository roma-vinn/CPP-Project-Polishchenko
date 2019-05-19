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

class Teacher : public Worker {
public:
    Teacher(std::string name);
    Teacher(std::string name, int age);
    Teacher(std::string name, std::string degree);
    Teacher(std::string name, int age, std::string degree);

    ~Teacher() {};
    void setDegree(std::string degree);
    std::string getDegree() { return _degree; };

    float income();

    std::string getInfo();
private:
    std::string _degree = "None";
//    std::vector<Student>
    static const std::map<std::string, float> _degreeFactor;
    static const float _salary;
};

#endif /* Teacher_hpp */
