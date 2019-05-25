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

extern bool LOGGING;
extern string logs;

// ==================== Human ==================== //

/*
 Abstract Human class.
 Contains information about name and age of person.
 */
class Human {
public:
    /* create human with given name and age
     @param name: person's name
     @param age: person's age
     */
    Human(string name, int age);
    
    /* default destructor
     */
    ~Human() {};
    
    /* getter for the name
     */
    string getName() { return _name; };
    
    /* getter for the age
     */
    int getAge() { return _age; };
    
    /* setter for the name
     @param name: new name
     */
    void setName(string name);
    
    /* setter for the age
     @param age: new age
     */
    void setAge(int age);
    
    /* pure virtual method that will return the income of the person
     */
    virtual float income() = 0;
    
    /* virtual method that return string
     representation of info about this person
     in format: "Name, age, "
     */
    virtual string getInfo();
private:
    /* field that contains person's name
     */
    string _name = "";
    
    /* field that contains person's age
     */
    int _age = 0;
};

#endif /* Human_hpp */
