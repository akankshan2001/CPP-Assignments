/*
Problem Statement:
Write a program to create namespace in one file and access the contents using another program.
a) Create two files, one containing the namespace and all the data members and member functions that we 
want to use later.(Eg: file1.h) and other file containing the nested namespace with data members that we want to use 
later.(Eg:file2.h) 
b) One program can directly call the first and second program to use all the data members 
and member functions in it. (file3.cpp)

*/

#include <iostream>
#include "file1.h"
#include "file2.h"

int main() {

    MyNamespace::printGlobalVar();  //from file1
    MyNamespace::NestedNamespace::printNestedVar(); //from file2

    return 0;
}
