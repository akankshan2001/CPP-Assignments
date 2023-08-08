/*

For a given array of integers, reach to the end of the array from the 0th index with minimum number of moves. 
Moves possible at each index:

Move from index i to index (i+1)
Move from index i to index (i-1)
Move from index i to index j, if a[i] == a[j]

Input
The first line of each test case contains a single integer T 
denoting the number of test cases. Each test consists of two lines. 
First line denotes N the number of elements in the array. Second line contains N space separated integers.

Output
For each test case, output a single line containing minimum number of moves possible

Constraints
1 ≤ T ≤ 20
1 ≤ N ≤ 20
1 ≤ Ai ≤ 105
Example
Input:
2
6
1 2 3 4 5 6
11
2 3 5 1 4 3 2 6 7 8 4

Output:
5
5

*/

#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    
    int T;
    std::cout<<"Enter number of test cases: "<<std::endl;
    std::cin >> T;

    while (T--) {
        int N;
        std::cout<<"How many elements are to be stored into array?"<<std::endl;
        std::cin >> N;
        std::vector<int> arr(N);  //initialized array of size N

        std::cout<<"Enter array elements:"<<std::endl;
        for (int i = 0; i < N; ++i) {
            std::cin >> arr[i];
        }

        //dp array -->> represents the minimum number of moves required to reach index from 0th index
        std::vector<int> dp(N, INT_MAX); 
        dp[0] = 0;

        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] == arr[j]) {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
            dp[i] = std::min(dp[i], dp[i - 1] + 1);
        }
        
        std::cout << dp[N - 1] << std::endl;
       
    }


    return 0;
}
