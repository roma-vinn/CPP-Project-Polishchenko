//
//  University.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "University.hpp"

//extern bool flag;

template<typename T>
void showVector(std::vector<T*> vect) {
    for (typename std::vector<T*>::const_iterator it = vect.begin(),
         end = vect.end(); it != end; ++it) {
        std::cout << (*it)->getInfo() << '\n';
    }
}

int read_from_console(std::vector<Teacher*> & all_teachers,
                      std::vector<Worker*> & all_workers,
                      std::vector<Student*> & all_students){
    int count = 0;
    std::cout << "Enter the number of Workers in University: ";
    std::cin >> count;
    if (count < 0) {
        std::cout << "Incorrect number: " << count <<
        ". Should be not less than 0.\n";
        return 1;
    } else {
        for (int i = 1; i < count + 1; ++i) {
            
            int age = 0, base_rate = 0, seniority = 0;
            std::string name = "", job_name="None";
            
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
            all_workers.push_back(new Worker(name, age, job_name,
                                             base_rate, seniority));
        }
        
        std::cout << "Enter the number of Teachers in University: ";
        std::cin >> count;
        if (count < 0) {
            std::cout << "Incorrect number: " << count <<
            ". Should be not less than 0.\n";
            return 1;
        } else {
            for (int i = 1; i < count + 1; ++i) {
                
                int age = 0, student_number = 0;
                std::string name = "", degree="None";
                
                std::cout << "Teacher " << i << ":\n";
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Age: ";
                std::cin >> age;
                std::cout << "Degree: ";
                std::cin >> degree;
                Teacher* t = new Teacher(name, age, degree);
                std::cout << "Enter the number of this teacher's students: ";
                std::cin >> student_number;
                if (student_number < 0) {
                    std::cout << "Incorrect number: " << count <<
                    ". Should be not less than 0.\n";
                    return 1;
                } else {
                    std::string name = "";
                    int age = 0, sub_number = 0;
                    RecordBook rb;
                    for (int j = 1; j < student_number + 1; ++j) {
                        std::cout << "Student " << j << ":\n";
                        std::cout << "Name: ";
                        std::cin >> name;
                        std::cout << "Age: ";
                        std::cin >> age;
                        std::cout << "Number of subjects: ";
                        std::cin >> sub_number;
                        if (sub_number < 0) {
                            std::cout << "Incorrect number: " << count <<
                            ". Should be not less than 0.\n";
                        } else {
                            for (int k = 1; k < sub_number + 1; ++k) {
                                std::string sub_name = "";
                                int grade_point = 0;
                                std::cout << "Subject name: ";
                                std::cin >> sub_name;
                                std::cout << "Grade point for " << sub_name << ": ";
                                std::cin >> grade_point;
                                rb.updateSubject(sub_name, grade_point);
                            }
                        }
                        Student student(name, age, rb);
                        t->addStudent(student);
                        all_students.push_back(new Student(name, age, rb));
                    }
                }
                all_teachers.push_back(t);
            }
        }
    }
    
    return 0;
}

int console_mode() {
    std::vector<Teacher*> all_teachers;
    std::vector<Worker*> all_workers;
    std::vector<Student*> all_students;
    
    if (read_from_console(all_teachers, all_workers, all_students)) {
        std::cout << "Incorrect input.\n";
        return 1;
    }
    
    bool flag = true;
    int choice = 1;
    while (flag) {
        std::cout << "";
        std::cin >> choice;
        
    }
    
    std::cout << "All workers:\n";
    showVector(all_workers);

    std::cout << "All teachers:\n";
    showVector(all_teachers);

    std::cout << "All students:\n";
    showVector(all_students);
    
    
    return 0;
}
