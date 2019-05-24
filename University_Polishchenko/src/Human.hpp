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

using namespace std;

/*
 Abstract Human class.
 
 Has 'name' and 'age' properties with
 corresponding getters [string getName(), int getAge()]
 and setters [setName(string name), setAge(int age)].
 */
class Human {
public:
//    Human(string name);
    Human(string name, int age);
    ~Human() {};
    string getName() { return _name; };
    int getAge() { return _age; };
    void setName(string name);
    void setAge(int age);
    virtual float income() = 0;
    
    virtual string getInfo();
private:
    string _name = "";
    int _age = 0;
};

#endif /* Human_hpp */
