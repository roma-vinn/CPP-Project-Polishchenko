//
//  RecordBook.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "RecordBook.hpp"

RecordBook::RecordBook(vector<string> subjects) {
    // initialization of empty record book
    for (vector<string>::const_iterator it = subjects.begin(),
         end = subjects.end();
         it != end; ++it) {
        _book[*it] = 0;
    }
    
    _grade_point_avg = 0;
    
    // logging
    if (LOGGING) {
        logs += "Called RecordBook constructor with params: <";
        for (int i = 0; i < subjects.size(); ++i) {
            if (i!=0) {
                logs += ", ";
            }
            logs += subjects[i];
        }
        logs += ">\n";
    }
}

RecordBook::RecordBook(map<string, int> record_book) {
    float avg = 0;
    for (map<string, int>::const_iterator it = record_book.begin(),
         end = record_book.end();
         it != end; ++it) {
        if (it->second > 100 || it->second < 0) {
            cout << "Invalid grade point: " << it->second <<
            " for " << it->first << ". Should be from 0 to 100.\n";
        } else {
            _book[it->first] = it->second;
            avg += it->second;
        }
    }
    _grade_point_avg = avg / record_book.size();
    
    // logging
    if (LOGGING) {
        logs += "Called RecordBook constructor with params: <";
        for (map<string, int>::const_iterator it = record_book.begin(),
             end = record_book.end(); it != end; ++it) {
            if (it!=record_book.begin()) {
                logs += ", ";
            }
            logs += it->first + ":" + to_string(it->second);
        }
        logs += ">\n";
    }
}

void RecordBook::updateSubject(string sub_name, int grade_point) {
    if (grade_point < 0 || grade_point > 100) {
        cout << "Invalid grade point: " << grade_point <<
        ". Should be from 0 to 100.\n";
    } else {
        _book[sub_name] = grade_point;
        
        // recount avarage grade point
        float avg = 0;
        
        for (map<string, int>::const_iterator it = _book.begin(),
             end = _book.end();
             it != end; ++it) {
            avg += it->second;
        }
        
        _grade_point_avg = avg / _book.size();
    }
    
    // logging
    if (LOGGING) {
        logs += "Called RecordBook method 'updateSubject' with params: <";
        logs += sub_name + ", " + to_string(grade_point) + ">\n";
    }
}

string RecordBook::getRepr() {
    string repr = "";
    for (map<string, int>::const_iterator it = _book.begin(),
         end = _book.end();
         it != end; ++it) {
        repr += it->first + " - " + to_string(it->second) + '\n';
    }
    repr += "Grade point avarage - " + to_string(_grade_point_avg) + '\n';
    
    // logging
    if (LOGGING) {
        logs += "Called RecordBook method 'getRepr'\n";
    }
    
    return repr;
}
