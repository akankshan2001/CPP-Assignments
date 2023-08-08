#ifndef FILE2_H
#define FILE2_H

#include <iostream>

namespace MyNamespace {
    namespace NestedNamespace {
        double nestedVar = 3.14;

        void printNestedVar() {
            std::cout << "NestedVar from NestedNamespace: " << nestedVar << std::endl;
        }
    }
}

#endif // FILE2_H
