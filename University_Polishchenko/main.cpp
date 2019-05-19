//
//  main.cpp
//  University_Polishchenko
//
//  Created by Roman Polishchenko on 5/18/19.
//  Copyright © 2019 Roman Polishchenko. All rights reserved.
//

#include <iostream>
#include "src/Worker.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Worker w("", "", 100000);
    cout << w.getInfo() << endl;
    return 0;
}
