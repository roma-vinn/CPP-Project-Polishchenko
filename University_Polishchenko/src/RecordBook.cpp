//
//  RecordBook.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "RecordBook.hpp"

RecordBook::RecordBook(std::vector<std::string> subjects) {
    // initialization of empty record book
    for (std::vector<std::string>::const_iterator it = subjects.begin(),
         end = subjects.end();
         it != end; ++it) {
        _book[*it] = 0;
    }
    
    _grade_point_avg = 0;
}

RecordBook::RecordBook(std::map<std::string, int> record_book) {
    int avg = 0;
    for (std::map<std::string, int>::const_iterator it = record_book.begin(),
         end = record_book.end();
         it != end; ++it) {
        if (it->second > 100 || it->second < 0) {
            std::cout << "Invalid grade point: " << it->second <<
            " for " << it->first << ". Should be from 0 to 100.\n";
        } else {
            _book[it->first] = it->second;
            avg += it->second;
        }
    }
    _grade_point_avg = avg / record_book.size();
}

void RecordBook::addSubject(std::string sub_name, int grade_point) {
    if (grade_point < 0 || grade_point > 100) {
        std::cout << "Invalid grade point: " << grade_point <<
        ". Should be from 0 to 100.\n";
    } else {
        _book[sub_name] = grade_point;
        
        // recount avarage grade point
        int avg = 0;
        
        for (std::map<std::string, int>::const_iterator it = _book.begin(),
             end = _book.end();
             it != end; ++it) {
            avg += it->second;
        }
        
        _grade_point_avg = avg / _book.size();
    }
}
