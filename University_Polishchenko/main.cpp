//
//  main.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include <iostream>
#include "src/Worker.hpp"
#include "src/Teacher.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Worker test
    Worker w("Antony", "Burglar", 100000);
    cout << w.getInfo() << endl;
    
    // Teacher test
    Teacher t1("Teacher1");
    Teacher t2("Teacher2", "Master");
    Teacher t3("Teacher3", "Master");
    t3.setExperience(12);
    
    cout << t1.getInfo() << endl;
    cout << t2.getInfo() << endl;
    cout << t3.getInfo() << endl;
    
    return 0;
}
