#include "llrec.h"
#include <iostream>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


// // approach 1
// void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
// // if empty 
// if (head == nullptr){return;}
// // to remember where initial lits is
// Node* nextnode = head->next;


// //Base Case 
// if (head->next == nullptr){ return; }
// // Work 
// if (head-> val <= pivot){ head->next = smaller;
// smaller = head;}

// else { head->next =  larger;
// larger = head;}
// head = nullptr;
// // Recursive call in both if statemens
// llpivot(nextnode, smaller, larger, pivot);
// }


Node *smaller = nullptr;
Node *larger = nullptr;

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == nullptr) { return; }

Node *nextnode = head->next;
    if (head->val <= pivot) { head->next = smaller;
        smaller = head; }
    else {head->next = larger;
        larger = head;} 

    // Move the pointer to the next node
    head = nextnode;

    // Recursively call - make sure to check if original list is empty
    llpivot(head, smaller, larger, pivot);}





//approach 2
// void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
// {

//   if(head == nullptr)
//   { return; }

//   if(head->val <= pivot)   {
    
//        smaller = head; 
//     head = head->next;
// smaller->next = NULL;
//     llpivot(head, smaller->next, larger, pivot); } 

// else if(head->val > pivot) { 
// //change to large
//     larger = head;
//     head = head->next;
//     larger->next = NULL;
// // recursive call again
//     llpivot(head, smaller, larger->next, pivot); }}