/*
Description
Problem Statement:
Write a program to calculate the distance between two points using structure.

Example:

Input: x1, y1 = (3, 4)
x2, y2 = (7, 7)

Output: 5

Input: x1, y1 = (3, 4)
x2, y2 = (4, 3)

Output: 1.41421
*/
/*
Distance formula:
d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

*/

#include <iostream>
#include <cmath> // for sqrt()

// Define a structure to represent a point
struct Point {
    double x;
    double y;
};

// Function to calculate the distance between two points
double calculateDistance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1, p2;

    // Input coordinates of the first point
    std::cout << "Enter x1 and y1: ";
    std::cin >> p1.x >> p1.y;

    // Input coordinates of the second point
    std::cout << "Enter x2 and y2: ";
    std::cin >> p2.x >> p2.y;

    // Calculate the distance
    double distance = calculateDistance(p1, p2);

    // Output the result
    std::cout << "Distance between the points: " << distance << std::endl;

    return 0;
}


