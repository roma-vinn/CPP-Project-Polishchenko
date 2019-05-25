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

// ==================== RecordBook ==================== //
/*
 Class that implements RecordBook for students.
 */
class RecordBook {
public:
    /* default constructor - create empty record book
     */
    RecordBook() {};
    
    /* create record book with given subjects (0 for each subject)
     @param subjects: names of the subjects
     */
    RecordBook(vector<std::string> subjects);
    
    /* create record book with given subjects and grade points for them
     @param record_book: map {subject name: grade point for it}
     */
    RecordBook(map<std::string, int> record_book);
    
    /* default destructor
     */
    ~RecordBook() {};
    
    /* method for updating grade point for existing subject
     (or adding a new subject)
     @param sub_name: name of the subject
     @param grade_point: grade point for this subject
     */
    void updateSubject(std::string sub_name, int grade_point);
    
    /* method for getting avarage grade point of all subjects
     */
    float getAvgGradePoint() { return _grade_point_avg; };
    
    /* method for getting representation of record book to
     print it in the console. Returning string with each subject
     from new line and avarage grade point in the end.
     */
    string getRepr();
    
    /* method for getting representation of record book to print
     it to the logs.
     Returning string "subject1:grade_point1, subject2:grade_point2"
     */
    string getBook();
private:
    /* field that contains information about subjects and their grade points
     */
    map<string, int> _book {};
    
    /* field that contains information about current avarage grade point
     */
    float _grade_point_avg = 0.0;
};

#endif /* RecordBook_hpp */
