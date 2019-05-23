//
//  main.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include <iostream>
#include "tests/tests.hpp"
#include "src/University.hpp"

using namespace std;

// if you want to log
bool LOGGING = false;
bool flag = true;

int main(int argc, const char * argv[]) {
    
    int choice = 1;
    while (flag) {
        cout << "Choose and type the number of the action below:\n";
        cout << "1. Test functions.\n";
        cout << "2. Console mode.\n";
        cout << "3. Input from file.\n";
        cout << "4. Prepared example.\n";
        cout << "0. Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                if (tests()) {
                    cout << "\nSomething went wrong.\n";
                } else {
                    cout << "\nEverything OK.\n";
                }
                break;
                
            case 2:
                console_mode();
                break;
            case 0:
                flag = false;
                cout << "Shutting down...\n";
                break;
                
            default:
                cout << "Incorrect command. Choose one of the NUMBERS above.\n";
                break;
        }
    }
    
        
    return 0;
}
