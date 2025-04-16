#include "llrec.h"

/**
 * Recursive implementation of llfilter that removes nodes based on
 * a predicate function. Operates in O(n) time.
 */
// Rn
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
  //base case - if there lisr becomes empty 
   if (!head) {
  smaller = larger = nullptr;
 return; }
    
  Node* next = head->next;
  head->next = nullptr;
    llpivot(next, smaller, larger, pivot);
    // if statemens
if (head->val <= pivot) {
     head->next = smaller;
        smaller = head; } 
  else {
    head->next = larger;
  larger = head; }
  head = nullptr; }



// Node* llfilter(Node* head, Predicate p) {
//     // Base case: empty list
//     if (head == nullptr) {
//         return nullptr;}
    
//     // use recursion and go through  list 
//     Node* filtered_rest = llfilter(head->next, p);
  
//     // Check if current node should be kept
//     if (p(head->val)) {
//         // Delete current node and return filtered rest
//     delete head;
//    return filtered_rest; } else {
//        // Kkeep the current  node and thenn attach filtered rest
//        head->next = filtered_rest;
//      return head;} }



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




// void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
// {
//     if (head == nullptr) { return; }

// Node *nextnode = head->next;
//     if (head->val <= pivot) { head->next = smaller;
//         smaller = head; }
//     else {head->next = larger;
//         larger = head;} 

//     // Move the pointer to the next node
//     head = nextnode;

//     // Recursively call - make sure to check if original list is empty
//     llpivot(head, smaller, larger, pivot);}



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