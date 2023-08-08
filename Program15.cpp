/*
Problem Statement:
Given two integers (positive , negative or even 0) say a and b. Find the max value of a$b where $ is any arithmetic 
operation like multiply(*), Divide(/), Addition(+),Substraction(-). Use Exception Handling in this problem.
Input:
The first line will contain an integer T (number of test cases). Each test case will contain two integers a and b.
Output:
Print the max value of a$b.

Constraints:
1 < = T < = 100
-103<=a,b<=103

Example:
Input:
2
5 -5
4 0

Output:
10
inf (Exception should get arise)

EXPLANATION:
In test case 1: 5-(-5) = 10
In test case 2: 4/0 = Infinite

*/

#include <iostream>

using namespace std;

double calculate_max_value(int a, int b) {
    double max_value; 

    try {
        double result = a + b;
        max_value = max(max_value, result);
    } catch(...) {}

    try {
        double result = a - b;
        max_value = max(max_value, result);
    } catch(...) {}

    try {
        double result = a * b;
        max_value = max(max_value, result);
    } catch(...) {}

    try {
        if (b != 0) {
            double result = static_cast<double>(a) / b;
            max_value = max(max_value, result);
        } else {
            throw runtime_error("Division by zero");
        }
    } catch(...) {}

    return max_value;
}

int main() {
    int T;
    cout<<"Enter test cases: "<<endl;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int a, b;
        cout<<"Enter a and b: "<<std::endl;
        cin >> a >> b;
        double max_value = calculate_max_value(a, b);
        cout << "Maximum of all operations : "<< max_value << endl;
    }

    return 0;
}
