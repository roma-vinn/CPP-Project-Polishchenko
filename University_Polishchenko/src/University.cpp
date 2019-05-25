//
//  University.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "University.hpp"


template<typename T>
void _showVector(vector<T*> vect) {
    // logging
    if (LOGGING) {
        logs += "Called '_showVector' function\n";
    }
    
    for (typename vector<T*>::const_iterator it = vect.begin(),
         end = vect.end(); it != end; ++it) {
        cout << (*it)->getInfo() << '\n';
    }
}

// function to count how many particular chars is in the string
int _count_chars(string str, char chr) {
    // logging
    if (LOGGING) {
        logs += "Called '_count_chars' function with params: <";
        logs += str + ", " + chr + ">\n";
    }
    
    int count = 0;
    
    for (int i = 0; i<str.size(); ++i) {
        if (str[i] == chr) {
            ++count;
        }
    }
    
    return count;
}

int read_int(){
    // logging
    if (LOGGING) {
        logs += "Called 'read_int' function\n";
    }
    
    int num = 0;
    string s_num = "0";
    
    getline(cin, s_num, '\n');
    if (isdigit(s_num[0])) {
        num = stoi(s_num);
        
    } else {
        cout << "Incorrect input: should be integer. 0 will be used instead.\n";
    }
    return num;
}

int read_from_console(vector<Worker*> & all_workers,
                      vector<Teacher*> & all_teachers,
                      vector<Student*> & all_students){
    // logging
    if (LOGGING) {
        logs += "Called 'read_from_console' function\n";
    }
    
    int count = 0;
    cout << "Enter the number of Workers in University: ";
    count = read_int();
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
            age = read_int();
            cout << "Job: ";
            getline(cin, job_name, '\n');
            
            if (job_name.length() > 0 && job_name!= "None") {
                cout << "Base rate: ";
                base_rate = read_int();
                cout << "Seniority: ";
                seniority = read_int();
            } else {
                job_name = "None";
            }
            all_workers.push_back(new Worker(name, age, job_name,
                                             base_rate, seniority));
        }
        
        cout << "Enter the number of Teachers in University: ";
        count = read_int();
        if (count < 0) {
            cout << "Incorrect number: " << count <<
            ". Should be not less than 0.\n";
            return 1;
        } else {
            for (int i = 1; i < count + 1; ++i) {
                
                int age = 0, student_number = 0, seniority = 0;
                string t_name = "", degree="None";
                
                cout << "Teacher " << i << ":\n";
                cout << "Name: ";
                getline(cin, t_name, '\n');
                cout << "Age: ";
                age = read_int();
                cout << "Degree: ";
                getline(cin, degree, '\n');
                cout << "Seniority: ";
                seniority = read_int();
                Teacher* t = new Teacher(t_name, age, degree, seniority);
                cout << "Enter the number of this teacher's students: ";
                student_number = read_int();
                if (student_number < 0) {
                    cout << "Incorrect number: " << count <<
                    ". Should be not less than 0.\n";
                    return 1;
                } else {
                    string s_name = "";
                    int age = 0, sub_number = 0;
                    RecordBook rb;
                    for (int j = 1; j < student_number + 1; ++j) {
                        cout << "Student " << j << ":\n";
                        cout << "Name: ";
                        getline(cin, s_name, '\n');
                        cout << "Age: ";
                        age = read_int();
                        cout << "Number of subjects: ";
                        sub_number = read_int();
                        if (sub_number < 0) {
                            cout << "Incorrect number: " << sub_number <<
                            ". Should be not less than 0.\n";
                        } else {
                            for (int k = 1; k < sub_number + 1; ++k) {
                                string sub_name = "";
                                int grade_point = 0;
                                cout << "Subject name: ";
                                getline(cin, sub_name, '\n');
                                cout << "Grade point for " << sub_name << ": ";
                                grade_point = read_int();
                                rb.updateSubject(sub_name, grade_point);
                            }
                        }
                        Student student(s_name, age, t_name, rb);
                        t->addStudent(student);
                        all_students.push_back(new Student(s_name, age, t_name, rb));
                    }
                }
                all_teachers.push_back(t);
            }
        }
    }
    
    return 0;
}

int read_from_files(string workers_path,
                    string teachers_path,
                    string students_path,
                    vector<Worker*> & all_workers,
                    vector<Teacher*> & all_teachers,
                    vector<Student*> & all_students)
{
    // logging
    if (LOGGING) {
        logs += "Called 'read_from_files' function\n";
    }
    
    fstream w_file(workers_path), t_file(teachers_path), s_file(students_path);
    if (!w_file.is_open()) {
        cout << "Workers file hasn't opened.\n";
        return 1;
    }
    if (!t_file.is_open()) {
        cout << "Teachers file hasn't opened.\n";
        return 1;
    }
    if (!s_file.is_open()) {
        cout << "Students file hasn't opened.\n";
        return 1;
    }
    
    // input workers' data
    while (!w_file.eof()) {
        string line = "", worker_name = "",
        job_name = "None";
        int age = 0, base_rate = 0, seniority = 0;
        size_t sep_pos = 0;
        
        getline(w_file, line, '\n');
        
        // check if it isn't the last "" line
        if (line.size() <= 1) {
            continue;
        }
        
        // check correctness of format
        if (_count_chars(line, ',') != 4 && line.size() > 1) {
            cout << "Incorrect format of input data for workers' input.\n";
            continue;
        }
        
        try {
            // input name
            sep_pos = line.find(',');
            worker_name = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            // input age
            sep_pos = line.find(',');
            age = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            // input job_name
            sep_pos = line.find(',');
            job_name = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            // input base_rate
            sep_pos = line.find(',');
            base_rate = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            // input seniority
            sep_pos = line.find(',');
            seniority = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            Worker *w = new Worker(worker_name, age, job_name,
                                   base_rate, seniority);
            if (worker_name != "") {
                all_workers.push_back(w);
            }
        } catch (...) {
            cout << "Smth went wrong with workers' input.\n";
            continue;
        }
        
    }
    
    // input teachers' data
    while (!t_file.eof()) {
        string line = "", teacher_name = "",
        degree = "None";
        int age = 0, seniority = 0;
        size_t sep_pos = 0;
        
        getline(t_file, line, '\n');
        
        // check if it isn't the last "" line
        if (line.size() <= 1) {
            continue;
        }
        
        // check correctness of format
        if (_count_chars(line, ',') != 3 && line.size() > 1) {
            cout << "Incorrect format of input data for teachers' input.\n";
            continue;
        }
        try {
            // input name
            sep_pos = line.find(',');
            teacher_name = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            // input age
            sep_pos = line.find(',');
            age = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            // input degree
            sep_pos = line.find(',');
            degree = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            // input seniority
            sep_pos = line.find(',');
            seniority = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            Teacher *t = new Teacher(teacher_name, age, degree, seniority);
            if (teacher_name != "") {
                all_teachers.push_back(t);
            }
        } catch (...) {
            cout << "Incorrect format of input data for workers input.\n";
            continue;
        }
        
    }
    
    while (!s_file.eof()) {
        string line = "", teacher_name = "", student_name = "",
        job_name = "None", sub_name = "";
        int age = 0, base_rate = 0, seniority = 0, grade_point = 0;
        size_t sep_pos = 0, sub_sep = 0;
        
        getline(s_file, line, '\n');
        
        // check if it isn't the last "" line
        if (line.size() <= 1) {
            continue;
        }
        
        // check correctness of format
        if (_count_chars(line, ',') < 5) {
            cout << "Incorrect format of input data for workers input.\n";
            continue;
        }
        try {
            // input name
            sep_pos = line.find(',');
            student_name = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            // input age
            sep_pos = line.find(',');
            age = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            // input job_name
            sep_pos = line.find(',');
            job_name = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            // input base_rate
            sep_pos = line.find(',');
            base_rate = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            // input seniority
            sep_pos = line.find(',');
            seniority = stoi(line.substr(0, sep_pos));
            line = line.substr(sep_pos + 2);
            
            // input teacher's name
            sep_pos = line.find(',');
            teacher_name = line.substr(0, sep_pos);
            line = line.substr(sep_pos + 2);
            
            RecordBook rb;
            
            while (line.size() > 2) {
                sub_sep = line.find(':');
                sub_name = line.substr(0, sub_sep);
                line = line.substr(sub_sep + 1);
                sep_pos = line.find(',');
                grade_point = stoi(line.substr(0, sep_pos));
                line = line.substr(sep_pos + 2);
                rb.updateSubject(sub_name, grade_point);
            }
            
            Student *s = new Student(student_name, age, job_name,
                                   base_rate, teacher_name, rb);
            s->setExperience(seniority);
            
            if (student_name != "") {
                all_students.push_back(s);
                
                for (int i = 0; i < all_teachers.size(); ++i) {
                    if (all_teachers[i]->getName() == teacher_name) {
                        all_teachers[i]->addStudent(s);
                        break;
                    }
                }
            }
        } catch (...) {
            cout << "Incorrect format of input data for workers input.\n";
            continue;
        }

    }
    
    return 0;
}

void showExistableData(vector<Worker*> & all_workers,
                       vector<Teacher*> & all_teachers,
                       vector<Student*> & all_students)
{
    // logging
    if (LOGGING) {
        logs += "Called 'showExistableData' function\n";
    }
    
    cout << "All workers:\n";
    _showVector(all_workers);
    
    cout << "All teachers:\n";
    _showVector(all_teachers);
    
    cout << "All students:\n";
    _showVector(all_students);
}

string overallStatistics(vector<Worker*> & all_workers,
                         vector<Teacher*> & all_teachers,
                         vector<Student*> & all_students){
    // logging
    if (LOGGING) {
        logs += "Called 'overallStatistics' function\n";
    }
    
    string output = "";
    float all_workers_income = 0,
    all_teachers_income = 0,
    all_students_income = 0;
    int top_scholarship = 0,
    mid_scholarship = 0;
    
    for (int i = 0; i < all_workers.size(); ++i) {
        all_workers_income += all_workers[i]->income();
    }
    
    for (int i = 0; i < all_teachers.size(); ++i) {
        all_teachers_income += all_teachers[i]->income();
    }
    
    for (int i = 0; i < all_students.size(); ++i) {
        all_students_income += all_students[i]->income();
        if (all_students[i]->getAvgGradePoint() >= 90) {
            ++top_scholarship;
        } else if (all_students[i]->getAvgGradePoint() >= 75) {
            ++mid_scholarship;
        }
    }
    output += "General expenses on the staff and students: " +
    to_string(all_workers_income + all_students_income + all_teachers_income) + '\n';
    
    output += "All workers together earning: " +
    to_string(all_workers_income) + '\n';
    output += "Avarage workers income: " +
    to_string(all_workers_income / all_workers.size()) + '\n';
    
    output += "All teachers together earning: " +
    to_string(all_teachers_income) + '\n';
    output += "Avarage teachers income: " +
    to_string(all_teachers_income / all_teachers.size()) + '\n';
    
    output += "All students together earning: " +
    to_string(all_students_income) + '\n';
    output += "Avarage students income: " +
    to_string(all_students_income / all_students.size()) + '\n';
    output += "Students that have top scholarship: " +
    to_string(top_scholarship) + '\n';
    output += "Students that have middle scholarship: " +
    to_string(mid_scholarship) + '\n';
    output += "Students that don't have scholarship: " +
    to_string(all_students.size() - top_scholarship - mid_scholarship) + '\n';
    
    return output;
}

int data_accounting(vector<Worker*> & all_workers,
                    vector<Teacher*> & all_teachers,
                    vector<Student*> & all_students) {
    // logging
    if (LOGGING) {
        logs += "Called 'data_accounting' function\n";
    }
    
    // show all existent data
    showExistableData(all_workers, all_teachers, all_students);
    bool flag = true, found = false;
    
    while (flag) {
        int choice = 1, age = 0, base_rate = 0, seniority = 0, sub_number = 0;
        string teacher_name = "", student_name = "",
        worker_name = "", job_name = "None", degree = "None";
        
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
        choice = read_int();
        
        switch (choice) {
                // 1. Show all workers.
            case 1:
                cout << "All workers:\n";
                _showVector(all_workers);
                break;
                
                // 2. Show all teachers.
            case 2:
                cout << "All teachers:\n";
                _showVector(all_teachers);
                break;
                
                // 3. Show all students.
            case 3:
                cout << "All students:\n";
                _showVector(all_students);
                break;
                
                // 4. Show all students of particular teacher.
            case 4:
                cout << "Name of the teacher: ";
                getline(cin, teacher_name, '\n');
                
                found = false;
                for (vector<Teacher*>::const_iterator it = all_teachers.begin(),
                     end = all_teachers.end(); it != end; ++it) {
                    if ((*it)->getName() == teacher_name) {
                        (*it)->showStudents();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Hasn't found such teacher. Check if the name is correct.\n";
                }
                break;
            
                // 5. Show avarage grade point of a student.
            case 5:
                cout << "Name of the student: ";
                getline(cin, student_name, '\n');
                
                found = false;
                for (vector<Student*>::const_iterator it = all_students.begin(),
                     end = all_students.end(); it != end; ++it) {
                    if ((*it)->getName() == student_name) {
                        cout << student_name << " avarage grade point - " <<
                        (*it)->getAvgGradePoint() << '\n';
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Hasn't found such student. Check if the name is correct.\n";
                }
                break;
                
                // 6. Show particular teacher students' avarage grade point.
            case 6:
                cout << "Name of the teacher: ";
                getline(cin, teacher_name, '\n');
                
                found = false;
                for (vector<Teacher*>::const_iterator it = all_teachers.begin(),
                     end = all_teachers.end(); it != end; ++it) {
                    if ((*it)->getName() == teacher_name) {
                        cout << teacher_name << "'s students avarage grade point - " <<
                        (*it)->getAvgGradePoint() << '\n';
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Hasn't found such teacher. Check if the name is correct.\n";
                }
                break;
               
                // 7. Add worker.
            case 7: {
                cout << "Worker name: ";
                getline(cin, worker_name, '\n');
                cout << "Age: ";
                age = read_int();
                cout << "Job: ";
                getline(cin, job_name, '\n');
                
                if (job_name.length() > 0 && job_name!= "None") {
                    cout << "Base rate: ";
                    base_rate = read_int();
                    cout << "Seniority: ";
                    seniority = read_int();
                }
                Worker *w = new Worker(worker_name, age, job_name,
                                       base_rate, seniority);
                if (w->getName() != "") {
                    all_workers.push_back(w);
                }
                break;
            }
                
                // 8. Add teacher.
            case 8: {
                cout << "Teacher name: ";
                getline(cin, teacher_name, '\n');
                cout << "Age: ";
                age = read_int();
                cout << "Degree: ";
                getline(cin, degree, '\n');
                cout << "Seniority: ";
                seniority = read_int();
                Teacher* t = new Teacher(teacher_name, age, degree, seniority);
                if (teacher_name != "") {
                    all_teachers.push_back(t);
                }
                break;
            }
                
                // 9. Add student.
            case 9: {
                teacher_name = "";
                RecordBook rb;
                cout << "Student name: ";
                getline(cin, student_name, '\n');
                cout << "Age: ";
                age = read_int();
                cout << "Job: ";
                getline(cin, job_name, '\n');
                
                if (job_name.length() > 0 && job_name!= "None") {
                    cout << "Base rate: ";
                    base_rate = read_int();
                    cout << "Seniority: ";
                    seniority = read_int();
                }
                cout << "Teacher's name: ";
                getline(cin, teacher_name, '\n');
                cout << "Number of subjects: ";
                sub_number = read_int();
                if (sub_number < 0) {
                    cout << "Incorrect number: " << sub_number <<
                    ". Should be not less than 0.\n";
                } else {
                    
                    for (int k = 1; k < sub_number + 1; ++k) {
                        string sub_name = "";
                        int grade_point = 0;
                        cout << "Subject name: ";
                        getline(cin, sub_name, '\n');
                        cout << "Grade point for " << sub_name << ": ";
                        grade_point = read_int();
                        if (sub_name != "") {
                            rb.updateSubject(sub_name, grade_point);
                        }
                    }
                }
                Student *s = new Student(student_name, age, teacher_name, rb);
                if (student_name != "") {
                    all_students.push_back(s);
                    for (int i = 0; i < all_teachers.size(); ++i) {
                        if (all_teachers[i]->getName() == teacher_name) {
                            all_teachers[i]->addStudent(s);
                            break;
                        }
                    }
                }
                break;
            }
                
                // 10. Show overall statistics.
            case 10:
                cout << overallStatistics(all_workers, all_teachers, all_students) << '\n';
                break;
                
                // 0. Exit.
            case 0:
                flag = false;
                break;
                
            default:
                cout << "Incorrect command: should be number [0, 1, .., 10].\n";
                break;
        }
        
    }
    return 0;
}
