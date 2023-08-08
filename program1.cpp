/*Description*/
/*Problem Statement:
Write a program in C++ which prints the numbers from 1 to 100. But, multiples of 3 should be replaced with "Fizz",
multiples of 5 should be replaced with "Buzz" and multiples of both 3 and 5 should be replaced with "FizzBuzz"?.*/

#include<iostream>

int main() {

    for(int i = 1; i<=100; i++) {
        
        if(i % 15 == 0) {
            std::cout<<"FizzBuzz"<<std::endl;  //first condition: multiple of 3 and 5 will obviously be the multiple of 15. Hence this will satisfy the condition ==> (i % 3 == 0 && i % 5 ==0)

        } else if(i % 3 == 0) {
            std::cout<<"Fizz"<<std::endl;  //second condition: multiple of 3. hence it will print ("Fizz")

        }else if(i % 5 == 0) {
            std::cout<<"Buzz"<<std::endl;  // third condition : multiple of 5. Hence it will print ("Buzz")

        } else {
            std::cout<<i<<std::endl; // Numbers unsatisfied by above three conditons will get print.
        }
    }

    return 0;
}