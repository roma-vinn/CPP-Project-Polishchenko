//
//  main.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include <iostream>
#include "tests/tests.hpp"
#include "src/University.hpp"

using namespace std;

// if you want to log
bool LOGGING = false;

// write path to your input files or rewrite existing
string workers_path = "workers_input.txt";
string teachers_path = "teachers_input.txt";
string students_path = "students_input.txt";
string output_path = "output.txt";
string logging_path = "logs.txt", logs="";

/* auxilary function that writes logs to the file (if LOGGING is true)
 */
void write_logs() {
    if (LOGGING) {
        fstream file(logging_path, ios::out);
        if (!file.is_open()) {
            cout << "Problem with logging file.\n";
        } else {
            file << logs;
        }
    }
}

int main(int argc, const char * argv[]) {
    // need logging ?
    string is_logging = "n";
    cout << "Make logs? y/n: ";
    getline(cin, is_logging, '\n');
    if (is_logging == "y") {
        LOGGING = true;
    } else if (is_logging != "n") {
        cout << "Incorrect input. Treated like 'n'.\n";
    }
    
    // need testing ?
    string is_test = "n";
    cout << "Test modules and functions? y/n: ";
    getline(cin, is_test, '\n');
    if (is_test == "y") {
        if (tests()) {
            cout << "\nSomething went wrong.\n";
        } else {
            cout << "\nEverything OK.\n\n";
        }
    } else if (is_test != "n") {
        cout << "Incorrect input. Treated like 'n'.\n";
    }
    
    vector<Worker*> all_workers;
    vector<Teacher*> all_teachers;
    vector<Student*> all_students;
    
    int choice = 1;
    // what type of input ?
    cout << "Choose and type the number of the action below:\n";
    cout << "1. Console input.\n";
    cout << "2. Input from files.\n";
    cout << "0. Exit.\n";
    choice = read_int();
    switch (choice) {
        case 1: {
            string is_reading = "y";
            while (is_reading == "y") {
                if (read_from_console(all_workers, all_teachers, all_students)) {
                    cout << "Incorrect input. Try again? y/n: \n";
                    getline(cin, is_reading, '\n');
                    if (is_reading == "y") {
                        continue;
                    } else if (is_test != "n") {
                        cout << "Incorrect input. Treated like 'n'.\n";
                        is_reading = false;
                        break;
                    }
                    
                } else {
                    is_reading = false;
                    break;
                }
            }
        }
        case 2:
            if (read_from_files(workers_path, teachers_path, students_path,
                                all_workers, all_teachers, all_students)) {
                cout << "Problems with files. Check paths/data style.\n";
                cout << "Shutting down...\n";
                write_logs();
                return 0;
            }
            
            break;
        case 0:
            cout << "Shutting down...\n";
            write_logs();
            return 0;
            
        default:
            cout << "Incorrect command. Input will be made from files.\n";
            if (read_from_files(workers_path, teachers_path, students_path,
                                all_workers, all_teachers, all_students)) {
                cout << "Problems with files. Check paths/data style.\n";
                cout << "Shutting down...\n";
                write_logs();
                return 0;
            }
    }

    // interact with data
    data_accounting(all_workers, all_teachers, all_students);
    
    // need to write statistics into the file ?
    string is_output = "n";
    cout << "Write statistics into 'output.txt'? y/n: ";
    getline(cin, is_output, '\n');
    if (is_output == "y") {
        fstream file(output_path, ios::out);
        if (!file.is_open()) {
            cout << "File hasn't opened. Check if file path specified correctly.\n";
        }
        file << overallStatistics(all_workers, all_teachers, all_students);
        file.close();
    } else if (is_output != "n") {
        cout << "Incorrect input. Treated like 'n'.\n";
    }
    
    cout << "Shutting down...\n";
    
    // write logs before exiting (if needed)
    write_logs();
    
    // memory will be cleaned automatically within default destructors
    return 0;
}
