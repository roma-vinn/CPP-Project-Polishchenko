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

// ==================== Main module ==================== //

/* function to work with data in the console. Available comands:
 1. Show all workers.
 2. Show all teachers.
 3. Show all students.
 4. Show all students of particular teacher.
 5. Show avarage grade point of a student.
 6. Show particular teacher students' avarage grade point.
 7. Add worker.
 8. Add teacher.
 9. Add student.
 10. Show overall statistics.
 0. Exit.
 */
int data_accounting(vector<Worker*> & all_workers,
                    vector<Teacher*> & all_teachers,
                    vector<Student*> & all_students);

/* auxiliary function to read int from console and procces incorrect input
 */
int read_int();

/* function to read information about staff from console
 */
int read_from_console(vector<Worker*> & all_workers,
                      vector<Teacher*> & all_teachers,
                      vector<Student*> & all_students);

/* function to read information about staff from files
 */
int read_from_files(string workers_path,
                    string teachers_path,
                    string students_path,
                    vector<Worker*> & all_workers,
                    vector<Teacher*> & all_teachers,
                    vector<Student*> & all_students);

/* function to get overall statistics about existing staff.
 return string containing required information
 */
string overallStatistics(vector<Worker*> & all_workers,
                         vector<Teacher*> & all_teachers,
                         vector<Student*> & all_students);

/* function to display all available data in the console
 */
void showExistableData(vector<Worker*> & all_workers,
                       vector<Teacher*> & all_teachers,
                       vector<Student*> & all_students);

#endif /* University_hpp */
