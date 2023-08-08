/*
Description
Problem Statement:
Write a program that takes Names as input and then sort names according to bases of first character of that Name in ascending order.

Input:
Enter the names:
Name1: Abc
Name2: Cup
Name3: Altavista
Name4: Yahoo
Name5: Mbni
Name6: Sun
Name7: Mani
Name8: Google
Name9: India
Name10: Watan

Output:
The sorted names are:
Abc
Altavista
Cup
Google
India
Mbni
Mani
Sun
Watan
Yahoo

Hints:
1) You can apply any sorting algorithm you want
2) You will be storing the names some thing like this,
char Name[10][25] ; // Ten Names each 25 character long.
3) You can use loop etc to get input and display output.
4) You can use strcpy() function to copy one string to another.
*/

#include <iostream>
#include <cstring>

using namespace std;

//This function swaps the letter and passes to the function from which it was called.


void swapNames(char names[][25], int i, int j) {
    char temp[25];
    strcpy(temp, names[i]);
    strcpy(names[i], names[j]);
    strcpy(names[j], temp);
}

void sortNames(char names[][25], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (names[j][0] > names[j + 1][0]) {
                swapNames(names, j, j + 1);
            }
        }
    }
}

int main() {
    const int numNames = 10;
    char names[numNames][25];

    cout << "Enter the names:" << endl;
    for (int i = 0; i < numNames; i++) {
        cout << "Name" << i + 1 << ": ";
        cin >> names[i];
    }

    sortNames(names, numNames);

    cout << "The sorted names are:" << endl;
    for (int i = 0; i < numNames; i++) {
        cout << names[i] << endl;
    }

    return 0;
}
