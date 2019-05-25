//
//  University.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef University_hpp
#define University_hpp

#include <iostream>
#include <fstream>
#include "Worker.hpp"
#include "Teacher.hpp"
#include "Student.hpp"

using namespace std;
extern bool LOGGING;
extern string logs;

int data_accounting(vector<Worker*> & all_workers,
                    vector<Teacher*> & all_teachers,
                    vector<Student*> & all_students);
int read_int();
int read_from_console(vector<Worker*> & all_workers,
                      vector<Teacher*> & all_teachers,
                      vector<Student*> & all_students);
int read_from_files(string workers_path,
                    string teachers_path,
                    string students_path,
                    vector<Worker*> & all_workers,
                    vector<Teacher*> & all_teachers,
                    vector<Student*> & all_students);

string overallStatistics(vector<Worker*> & all_workers,
                         vector<Teacher*> & all_teachers,
                         vector<Student*> & all_students);

void showExistableData(vector<Worker*> & all_workers,
                       vector<Teacher*> & all_teachers,
                       vector<Student*> & all_students);


#endif /* University_hpp */
