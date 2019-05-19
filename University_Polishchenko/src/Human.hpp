//
//  Human.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef Human_hpp
#define Human_hpp

#include <iostream>
#include <string>

/*
 Abstract Human class.
 
 Has 'name' and 'age' properties with
 corresponding getters [std::string getName(), int getAge()]
 and setters [setName(std::string name), setAge(int age)].
 */
class Human {
public:
    Human(std::string name);
    Human(std::string name, int age);
    ~Human() {};
    std::string getName() { return _name; };
    int getAge() { return _age; };
    void setName(std::string name);
    void setAge(int age);
    virtual float income() = 0;
    
private:
    std::string _name = "";
    int _age = 0;
};

#endif /* Human_hpp */
