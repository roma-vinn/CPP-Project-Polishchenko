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
#include "Worker.hpp"
#include "Teacher.hpp"
#include "Student.hpp"

int console_mode();
int read_from_console(std::vector<Teacher*> & all_teachers,
                      std::vector<Worker*> & all_workers,
                      std::vector<Student*> & all_students);

#endif /* University_hpp */
