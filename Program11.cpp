
/*
Description
Create a menu driven program to insert, erase, display & search Employees based on their ids & also names. 
Ensure that duplicate values could be inserted at runtime. 
Then use appropriate algorithm to perform sort based on their names and Demonstrate the use of a predicate 
to find an employee based on id.
Also, iterate using range based for loop algorithm.

*/

#include <iostream>
#include <list>
#include <algorithm>

/*
This defines a class Employee, which represents an employee with an ID and a name. 
The constructor takes an id and a name as parameters and initializes the private member variables. 
There are two member functions, getId() and getName(), which provide access to the private members.
*/

class Employee {
public:
    Employee(int id, const std::string& name) : id(id), name(name) {}
int I = 0;
    int getId() const {
        return id;
    }

    const std::string& getName() const {
        return name;
    }

private:
    int id;
    std::string name;
};

/*
Here, a predicate class FindById is defined. 
A predicate is a function or function object that returns a boolean value, 
used for making decisions in algorithms like find_if. In this case, 
FindById is designed to find an employee based on their ID.

 It takes an Employee as a parameter and compares its ID with the targetId. 
If the IDs match, it returns true, indicating a match.

*/

// Predicate to find an employee based on id
class FindById {
public:
    FindById(int targetId) : targetId(targetId) {}

    /*
    Searches the employess according to its id
    
    */

    bool operator()(const Employee& employee) {

        return employee.getId() == targetId;
        I++;
    }

private:
    int targetId;
};

int main() {
    std::list<Employee> employees;
    int choice;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Insert Employee\n";
        std::cout << "2. Erase Employee\n";
        std::cout << "3. Display Employees\n";
        std::cout << "4. Search Employee by ID\n";
        std::cout << "5. Sort Employees by Name\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        /*
        cin.ignore()
         clear the unwanted buffer, so when next input is taken, it stores into the desired container, 
         but not in the buffer of previous variable. For example, after entering into the cin statement, 
         we need to input a character array or string. 
         So we need to clear the input buffer, otherwise it will occupy the buffer of previous variable.
        
        */

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                std::cout << "Enter Employee ID: ";
                std::cin >> id;
                std::cout << "Enter Employee Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                //Adds the employee name at the back of vector
                employees.push_back(Employee(id, name));
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter Employee ID to Erase: ";
                std::cin >> id;
                employees.remove_if(FindById(id));  //if target id and employee id matches findById returns true 
                break;
            }
            case 3: {
                std::cout << "Employees:\n";
                for (const auto& employee : employees) {
                    std::cout << "ID: " << employee.getId() << ", Name: " << employee.getName() << std::endl;
                }
                break;
            }

            case 4: {
                int id;
                std::cout << "Enter Employee ID to Search: ";
                std::cin >> id;
                auto it = std::find_if(employees.begin(), employees.end(), FindById(id));
                if (it != employees.end()) {
                    std::cout << "Employee found: ID: " << it->getId() << ", Name: " << it->getName() << std::endl;
                } else {
                    std::cout << "Employee not found.\n";
                }
                break;
            }

            /* []-->lambda expression  */
            case 5: {
                employees.sort([](const Employee& a, const Employee& b) {
                    return a.getName() < b.getName();
                });
                std::cout << "Employees sorted by name.\n";
                break;
            }
            case 6: {
                std::cout << "Exiting.\n";
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
