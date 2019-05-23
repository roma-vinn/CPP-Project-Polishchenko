//
//  University.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "University.hpp"

extern bool flag;

template<typename T>
void showVector(std::vector<T*> vect) {
    for (typename std::vector<T*>::const_iterator it = vect.begin(),
         end = vect.end(); it != end; ++it) {
        std::cout << (*it)->getInfo() << '\n';
    }
}

int console_mode() {
    std::vector<Teacher*> teachers;
    std::vector<Worker*> workers;
    std::vector<Student*> students;
    
    int count = 0;
    std::cout << "Enter the number of Workers in University: ";
    std::cin >> count;
    if (count < 0) {
        std::cout << "Incorrect number: " << count <<
        ". Should be not less than 0.\n";
    } else {
        for (int i = 1; i < count + 1; ++i) {
            
            int age = 0, base_rate = 0, seniority = 0;
            std::string name, degree="None", job_name="None";
            
            std::cout << "Worker " << i << ":\n";
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "Job: ";
            std::cin >> job_name;
            
            if (job_name.length() > 0 && job_name!= "None") {
                std::cout << "Base rate: ";
                std::cin >> base_rate;
                std::cout << "Seniority: ";
                std::cin >> seniority;
            } else {
                job_name = "None";
            }
            workers.push_back(new Worker(name, age, job_name,
                                         base_rate, seniority));
        }
        
        std::cout << "Workers:\n";
        showVector(workers);
    
        // exit the program
        flag = false;
    }
    
    return 0;
}
