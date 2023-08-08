/*
Problem Statement:
Write a program to demonstrate the use of function object to find sum of all integer elements in the vector.

*/

/*

In this program, we define a SumFunctor class that overloads the function call operator (). 
The functor takes two arguments: the current sum and the current element. 
It returns the updated sum by adding the current element.

The main function creates a vector of integers, initializes the sum to 0, and then creates an 
instance of SumFunctor. We use the std::accumulate algorithm from the <numeric> header to compute the 
sum of the elements in the vector, using the SumFunctor as the binary operation.

*/

#include<iostream>
#include<vector>
#include<numeric>

class FuncObj {

    public:
    //Operator() is overloaded
    int operator()(int sum, int element) const {
        
        return sum + element;
    
    }

};

int main() {

    std::vector<int> numbers = {1,2,3,4,5};

    FuncObj obj;

    int sum = std::accumulate(numbers.begin(),numbers.end(),0,obj);

    std::cout<< "Sum : " << sum << std::endl;

    return 0;

}