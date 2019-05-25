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

using namespace std;
extern bool LOGGING;
extern string logs;

// points from 0 to 100
class RecordBook {
public:
    RecordBook() {};
    RecordBook(vector<std::string> subjects);
    RecordBook(map<std::string, int> record_book);
    ~RecordBook() {};
    void updateSubject(std::string sub_name, int grade_point);
    float getAvgGradePoint() { return _grade_point_avg; };
    string getRepr();
    string getBook();
private:
    map<string, int> _book {};
    float _grade_point_avg = 0.0;
};

#endif /* RecordBook_hpp */
