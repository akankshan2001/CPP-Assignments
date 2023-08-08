/*
Description
Problem Statement:
Write a program that prints the calendar of a month, given the total number of days and the first day (0:Monday..6:Sunday ) of that month. Say, the No. of days is 31 and the first day is Tuesday, then the output looks like what’s given below.

Output:
0   1   2   3   4   5   6
Mon Tue Wed Thr Fri Sat Sun
     1   2   3   4   5   6
 7   8   9   10  11  12  13
 14  15  16  17  18  19  20
 21  22  23  24  25  26  27
 28  29  30  31
*/

#include <iostream>
#include <iomanip> //for formatting output ==>> stew() ==> for field width

// Step by step evaluating the problem statement

void print_calendar(int days, int first_day)
{

    int current_day = 1;

    std::string weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    for (int i = 0; i < 7; i++)
    {
        std::cout << std::setw(4) << weekdays[i];
    }

    std::cout << std::endl;

    for (int week = 0; current_day <= days; week++)
    {

        for (int day = 0; day < 7; day++)
        {
              // Fill empty spaces in the first week if necessary.
            if (week == 0 && day < first_day)
            {
                std::cout << std::setw(4) << " ";
            }
             // Print the current day if within the specified days.
            else if (current_day <= days)
            {
                std::cout << std::setw(4) << current_day;
                current_day++;
            }
        }

        std::cout << std::endl;
    }
}

int main()
{
    int no_of_days, first_day;
    std::cout << "Enter number of days: " << std::endl;
    std::cin >> no_of_days;
    
    if (no_of_days >= 28 && no_of_days<=31)
    {
        std::cout << "Enter first day: " << std::endl;
        std::cin >> first_day;

        print_calendar(no_of_days, first_day);

        std::cout << std::endl;
    }
    else
    {
        std::cout << "Mention again..Month cannot have days more than 31 and less than 28!" << std::endl;
    }

    return 0;
}
