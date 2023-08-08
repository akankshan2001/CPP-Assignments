
/*
Problem Statement:
1) Create a class template of multiple parameters to display the modulus of numbers using constructor.
*/
#include <iostream>

template <typename T>
class ModulusCalculator {
private:
    T number;
    T modulus;

public:
    ModulusCalculator(T num, T mod) : number(num), modulus(mod) {}

    void calculateModulus() {
        T result = number % modulus;
        std::cout << "Modulus of " << number << " % " << modulus << " = " << result << std::endl;
    }
};

int main() {
    ModulusCalculator<int> intModulus(10, 3);
    intModulus.calculateModulus();

    ModulusCalculator<int> anotherIntModulus(15, 4);
    anotherIntModulus.calculateModulus();

    return 0;
}



