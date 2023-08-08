/*
Description
Problem Statement:
Write a program to count the number of times a particular string appears in a string container class. 
Then replace the corresponding occurrences by changing its case. 
Also, parse the string for any numeric values using string stream class using appropriate delimiters.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class StringContainer {
private:
    std::string data;

public:
    // Constructor to initialize the string container with data
    StringContainer(const std::string& input) : data(input) {}

    // Function to count the occurrences of a particular substring
    int countOccurrences(const std::string& target) const {
        int count = 0;
        size_t pos = data.find(target);

        while (pos != std::string::npos) {
            count++;
            pos = data.find(target, pos + 1);
        }

        return count;
    }

    // Function to replace corresponding occurrences by changing their case
    void replaceOccurrences(const std::string& target) {
        std::string lowerCaseTarget = target;
        std::transform(lowerCaseTarget.begin(), lowerCaseTarget.end(), lowerCaseTarget.begin(), ::tolower);

        size_t pos = data.find(target);

        while (pos != std::string::npos) {
            data.replace(pos, target.length(), lowerCaseTarget);
            pos = data.find(target, pos + 1);
        }
    }

    // Function to parse the string for numeric values using stringstream with appropriate delimiters
    void parseForNumericValues() {
        std::istringstream iss(data);
        std::string token;
        
        while (getline(iss, token, ' ')) {
            std::istringstream numStream(token);  //delimiter
            int num;
            if (numStream >> num) {
                std::cout << "Numeric value found: " << num << std::endl;
            }
        }
    }

    // Function to get the string data in the container
    std::string getString() const {
        return data;
    }
};

int main() {
    // Example usage of the StringContainer class
    std::string inputString = "This is a test string with test data and 123 numbers. Test TEST";
    StringContainer container(inputString);

    std::string target = "test";
    int occurrences = container.countOccurrences(target);

    std::cout << "Number of occurrences of '" << target << "': " << occurrences << std::endl;

    container.replaceOccurrences(target);
    std::cout << "String after replacing '" << target << "' with its lowercase version: " << container.getString() << std::endl;

    container.parseForNumericValues();

    return 0;
}
