//
//  test_RecordBook.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/22/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include "test_RecordBook.hpp"

int testRecordBook() {
    try {
        vector<string> subjects {"Math", "History"};
        map<string, int> record_book {{"Math", 100}, {"History", 80}};
        
        // test constructors
        RecordBook rb1;
        RecordBook rb2(subjects);
        RecordBook rb3(record_book);
        
        // test 'getAvgGradePoint' and correctness of result
        if (rb3.getAvgGradePoint() != 90) {
            throw ;
        }
        
        // test 'updateSubject' and correctness of result
        rb2.updateSubject("Math", 100);
        if (rb2.getAvgGradePoint() != 50) {
            throw ;
        }
        
        // test 'getRepr' and correctness of result
        string res = "History - 0\nMath - 100\nGrade point avarage - 50.000000\n";
        if (rb2.getRepr() != res) {
            throw ;
        }
        
    } catch (...) {
        return -1;
    }
    
    return 0;
}
