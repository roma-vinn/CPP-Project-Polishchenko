//
//  main.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include <iostream>
#include "tests/tests.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    if (tests()) {
        cout << "Something went wrong.\n";
    } else {
        cout << "\nEverything OK.\n";
    }
        
    return 0;
}
