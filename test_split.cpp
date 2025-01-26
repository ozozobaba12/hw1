/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printList(Node* head) {
    
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "nullptr\n";
}

int main() {
    // Create a test list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* node5 = new Node (5, nullptr);
    Node* node4 = new Node (4, nullptr);
    Node* node3 = new Node (3, nullptr);
    Node* node2 = new Node (2, nullptr);
    Node* node1 = new Node (1, nullptr);

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;


    // Initialize empty odd and even lists
    Node* odds = nullptr;
    Node* evens = nullptr;

    //cout<<node1->value<<" "<< node1->next->value<<" "<<node2->next->value<<" "<<node3->next->value<<" "<<node4->next->value<<" "<<endl;
    //Checking if the nodes are linked properly.

    // Call the split function
    split(node1, odds, evens);



    // Print the results
    cout << "Original List: 1 -> 2 -> 3 -> 4 -> 5 nullptr\n";
    cout << "Odd List: ";
    printList(odds);
    cout << "Even List: ";
    printList(evens);

    

    while (odds!=nullptr){
        Node* temp_odds=odds;
        odds=odds->next;
        delete temp_odds;
    }

     while (evens!=nullptr){
        Node* temp_evens=evens;
        evens=evens->next;
        delete temp_evens;
    }

    return 0;
}
