/*
Description
Problem Statement:
Design a template class that is used to create a linked list of integers or floats.
Implement 'insert' and 'delete' operations along with the printing of elements.
Also, check whether the linked list is null or not.

Input:
6 2 7 1 3

Output:
Index
Iteration 0 1 2 3 4
0 6 2 7 1 3
1 2 6 7 1 3
2 2 6 7 1 3
3 1 2 6 7 3
4 1 2 3 6 7

Hint:
You can use any type of Linked List.
*/

// #include <iostream>

// struct Node
// {

//         int data;
//         struct Node *next;
// };

// struct Node *head = NULL;

// struct Node *createNode()
// {

//         struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

//         int data;
//         std::cout << "Enter data:" << std::endl;
//         std::cin >> data;
//         newNode->data = data;
//         newNode->next = NULL;

//         return newNode;
// }

// void addAtFirst()
// {

//         struct Node *newNode = createNode();

//         if (head == NULL)
//         {
//                 head = newNode;
//         }
//         else
//         {
//                 struct Node *temp = head;
//                 head = newNode;
//                 newNode->next = temp;
//         }
// }

// void addAtLast()
// {

//         struct Node *newNode = createNode();

//         struct Node *temp = head;

//         while (temp->next != NULL)
//         {
//                 temp = temp->next;
//         }

//         temp->next = newNode;
// }

// int addAtPos(int pos)
// {

//         struct Node *newNode = createNode();

//         if (head == NULL)
//         {
//                 addAtFirst();
//         }
//         else
//         {
//                 struct Node *temp = head;

//                 while (pos - 2)
//                 {
//                         temp = temp->next;
//                 }

//                 newNode->next = temp->next;
//                 temp->next = newNode;
//         }

//         return pos;
// }

// int delFirst()
// {

//         if (head == NULL)
//         {
//                 return -1;
//         }
//         else if (head->next == NULL)
//         {
//                 free(head);
//         }
//         else
//         {
//                 struct Node *temp = head;
//                 head = head->next;
//                 free(temp);
//                 return 0;
//         }
// }

// int delLast()
// {

//         if (head == NULL){

//                 return -1;
//         }
//         else {

//                 struct Node *temp = head;
//                 while (temp->next->next != NULL)
//                 {
//                         temp = temp->next;
//                 }
//                 free(temp->next->next);
//                 temp->next = NULL;
//                 return 0;

//         }
// }

// int delAtPos(int pos)
// {

//         struct Node *temp1 = head;
//         struct Node *temp2 = head;

//         if (head == NULL)
//         {
//                 return -1;
//         }
//         else if (head->next == NULL)
//         {
//                 delFirst();
//         }
//         else if (temp1->next == NULL)
//         {
//                 delLast();
//         }
//         else
//         {
//                 while (pos - 2)
//                 {
//                         temp1 = temp1->next;
//                 }

//                 temp2 = temp1->next;
//                 temp1->next = temp1->next->next;
//                 free(temp2);
//         }
// }

// int printLinkedList()
// {

//         if (head == NULL)
//         {
//                 return -1;
//         }
//         else
//         {

//                 struct Node *temp = head;

//                 while (temp != NULL)
//                 {

//                         std::cout << "|" << temp->data << "|";
//                         temp = temp->next;
//                 }

//                 std::cout << std::endl;
//         }
// }

// int main()
// {

//         struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//         int choice;
//         char ch;

//         do
//         {

//                 std::cout << "1.Add at first" << std::endl;
//                 std::cout << "2.Add Last" << std::endl;
//                 std::cout << "3.Add at position" << std::endl;
//                 std::cout << "4.Delete First" << std::endl;
//                 std::cout << "5.Delete Last" << std::endl;
//                 std::cout << "6.Delete at pos" << std::endl;
//                 std::cout << "7.Print LinkedList" << std::endl;

//                 std::cout << "Enter your choice:" << std::endl;
//                 std::cin >> choice;

//                 switch (choice)
//                 {

//                 case 1:
//                         addAtFirst();
//                         break;

//                 case 2:
//                 {
//                         int pos;
//                         std::cout << "Enter position: " << std::endl;
//                         std::cin >> pos;
//                         int ind = addAtPos(pos);

//                         std::cout << "Node added at pos: " << ind << std::endl;

//                         break;
//                 }

//                 case 3:
//                 {

//                         addAtLast();
//                         break;
//                 }

//                 case 4:
//                 {

//                         delFirst();
//                         break;
//                 }

//                 case 5:
//                 {

//                         delLast();
//                         break;
//                 }

//                 case 6:
//                 {
//                         int pos;
//                         std::cout << "Enter position:" << std::endl;
//                         delAtPos(pos);
//                         break;
//                 }

//                 case 7:
//                 {
//                         printLinkedList();
//                         break;
//                 }

//                 default:
//                         std::cout << "Invalid case!!" << std::endl;
//                         break;
//                 }

//                 std::cout << "Dou you wish to continue?(Y|N)" << std::endl;

//         } while (ch == 'Y' || ch == 'y');

//         return 0;
// }

#include <iostream>

// Template class for a Node in the Linked List
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

// Template class for the Linked List
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert an element at the end of the linked list
    void insert(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete an element from the linked list
    void deleteElement(const T& value) {
        if (head == nullptr) {
            std::cout << "The linked list is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        std::cout << "Element not found in the linked list." << std::endl;
    }

    // Function to check if the linked list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Function to print the elements in the linked list
    void print() const {
        Node<T>* current = head;
        int index = 0;
        std::cout << "Index" << std::endl;
        while (current != nullptr) {
            std::cout << "Iteration " << index++ << ": ";
            std::cout << current->data << " ";
            current = current->next;
            std::cout << std::endl;
        }
    }
};

int main() {
    LinkedList<int> intLinkedList;
    LinkedList<float> floatLinkedList;

    // Input elements into the integer linked list
    intLinkedList.insert(6);
    intLinkedList.insert(2);
    intLinkedList.insert(7);
    intLinkedList.insert(1);
    intLinkedList.insert(3);

    // Input elements into the float linked list
    floatLinkedList.insert(6.1f);
    floatLinkedList.insert(2.2f);
    floatLinkedList.insert(7.3f);
    floatLinkedList.insert(1.4f);
    floatLinkedList.insert(3.5f);

    // Print the integer linked list
    std::cout << "Integer Linked List:" << std::endl;
    intLinkedList.print();

    // Print the float linked list
    std::cout << "\nFloat Linked List:" << std::endl;
    floatLinkedList.print();

    return 0;
}
