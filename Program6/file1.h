//file 1
/*
The code you provided is a C++ header file (file1.h)
 that defines a namespace called MyNamespace and contains a global variable and a member function.

*/
#include<iostream>

//These lines are known as include guards.
//They prevent the header file from being included multiple times in the same source file
// which can lead to compilation errors due to duplicate definitions.
// If FILE1_H has not been defined, the code between #ifndef and #endif will be included.
//ifndef and endif are the preprocessor directives.

#ifndef FILE1_H
#define FILE1_H

namespace MyNamespace {
    int globalVar = 42;

    void printGlobalVar() {
        std::cout << "GlobalVar from MyNamespace: " << globalVar << std::endl;
    }
}

#endif // FILE1_H
