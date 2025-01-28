/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

// using namespace std;

/* Add a prototype a helper function here if you need */
void split(Node*& in, Node*& odds, Node*& evens);
void addToEnd( Node*& temp, Node*& input);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

if (in==nullptr){
  return;
}

//temp node that shares value of in, this is so that in isnt changed
Node* input=in;
in=in->next;
input->next=nullptr;

//if head node is empty, make the head node the temp variable
if ((input->value)%2==0){
  if (evens==nullptr){
    evens=input;
  }

//use temp variable to advance through linked lists.I COMPLETELY GOT ABOUT THIS
  else {
    addToEnd(evens, input);
  
  }
  //cout<<"just added to evens: "<<input->value<<endl;
}

if ((input->value)%2==1){
  if (odds==nullptr){
    odds=input;
  }

//use temp variable to advance through linked lists.I COMPLETELY GOT ABOUT THIS
  else{
    addToEnd(odds,input);
   
  }

  //cout<<"just added to odds: "<<input->value<<endl;
}

split(in, odds, evens);



/* If you needed a helper function, write it here */

  
}

void addToEnd(Node*& temp, Node*& input){
  if(temp->next==nullptr){
    temp->next=input;
    return;
  }

  else{
    addToEnd(temp->next, input);
  }
}