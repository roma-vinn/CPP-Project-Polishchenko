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
void _showVector(vector<T*> vect) {
    for (typename vector<T*>::const_iterator it = vect.begin(),
         end = vect.end(); it != end; ++it) {
        cout << (*it)->getInfo() << '\n';
    }
}

int _read_from_console(vector<Teacher*> & all_teachers,
                       vector<Worker*> & all_workers,
                       vector<Student*> & all_students){
    int count = 0;
    cout << "Enter the number of Workers in University: ";
    cin >> count;
    if (count < 0) {
        cout << "Incorrect number: " << count <<
        ". Should be not less than 0.\n";
        return 1;
    } else {
        for (int i = 1; i < count + 1; ++i) {
            
            int age = 0, base_rate = 0, seniority = 0;
            string name = "", job_name="None";
            
            cout << "Worker " << i << ":\n";
            cout << "Name: ";
            getline(cin, name, '\n');
            cout << "Age: ";
            cin >> age;
            cout << "Job: ";
            getline(cin, job_name, '\n');
            
            if (job_name.length() > 0 && job_name!= "None") {
                cout << "Base rate: ";
                cin >> base_rate;
                cout << "Seniority: ";
                cin >> seniority;
            } else {
                job_name = "None";
            }
            all_workers.push_back(new Worker(name, age, job_name,
                                             base_rate, seniority));
        }
        
        cout << "Enter the number of Teachers in University: ";
        cin >> count;
        if (count < 0) {
            cout << "Incorrect number: " << count <<
            ". Should be not less than 0.\n";
            return 1;
        } else {
            for (int i = 1; i < count + 1; ++i) {
                
                int age = 0, student_number = 0;
                string name = "", degree="None";
                
                cout << "Teacher " << i << ":\n";
                cout << "Name: ";
                getline(cin, name, '\n');
                cout << "Age: ";
                cin >> age;
                cout << "Degree: ";
                cin >> degree;
                Teacher* t = new Teacher(name, age, degree);
                cout << "Enter the number of this teacher's students: ";
                cin >> student_number;
                if (student_number < 0) {
                    cout << "Incorrect number: " << count <<
                    ". Should be not less than 0.\n";
                    return 1;
                } else {
                    string name = "";
                    int age = 0, sub_number = 0;
                    RecordBook rb;
                    for (int j = 1; j < student_number + 1; ++j) {
                        cout << "Student " << j << ":\n";
                        cout << "Name: ";
                        getline(cin, name, '\n');
                        cout << "Age: ";
                        cin >> age;
                        cout << "Number of subjects: ";
                        cin >> sub_number;
                        if (sub_number < 0) {
                            cout << "Incorrect number: " << count <<
                            ". Should be not less than 0.\n";
                        } else {
                            for (int k = 1; k < sub_number + 1; ++k) {
                                string sub_name = "";
                                int grade_point = 0;
                                cout << "Subject name: ";
                                getline(cin, sub_name, '\n');
                                cout << "Grade point for " << sub_name << ": ";
                                cin >> grade_point;
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
    vector<Teacher*> all_teachers;
    vector<Worker*> all_workers;
    vector<Student*> all_students;
    
    if (_read_from_console(all_teachers, all_workers, all_students)) {
        cout << "Incorrect input.\n";
        return 1;
    }
    
    cout << "All workers:\n";
    _showVector(all_workers);
    
    cout << "All teachers:\n";
    _showVector(all_teachers);
    
    cout << "All students:\n";
    _showVector(all_students);
    
    bool flag = true;
    int choice = 1;
    while (flag) {
        cout << "Choose and type the number of the action below:\n";
        cout << "1. Show all workers.\n";
        cout << "2. Show all teachers.\n";
        cout << "3. Show all students.\n";
        cout << "4. Show all students of particular teacher.\n";
        cout << "5. Show avarage grade point of a student.\n";
        cout << "6. Show particular teacher students' avarage grade point.\n";
        cout << "7. Add worker.\n";
        cout << "8. Add teacher.\n";
        cout << "9. Add student.\n";
        cout << "10. Show overall statistics.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "All workers:\n";
                _showVector(all_workers);
                break;
                
                // TODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODO
            default:
                break;
        }
        
    }
    
    return 0;
}
