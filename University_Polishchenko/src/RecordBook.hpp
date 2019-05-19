//
//  RecordBook.hpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#ifndef RecordBook_hpp
#define RecordBook_hpp

#include <iostream>
#include <string>
#include <vector>
#include <map>

/*
 TODO: write short description
 0 - 100
 */
class RecordBook {
public:
    RecordBook(std::vector<std::string> subjects);
    RecordBook(std::map<std::string, int> record_book);
    ~RecordBook() {};
    void addSubject(std::string sub_name, int grade_point);
    float getAvgGradePoint() { return _grade_point_avg; };
private:
    std::map<std::string, int> _book {};
    float _grade_point_avg = 0.0;
};

#endif /* RecordBook_hpp */
