#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;


// /**
//  * Reads integers (separated by whitespace) from a file
//  * into a linked list.
//  *
//  * @param[in] filename
//  *  The name of the file containing the data to read
//  * @return
//  *  Pointer to the linked list (or NULL if empty or the
//  *  file is invalid)
//  */
// Node* readList(const char* filename);

// /**
//  * Prints the integers in a linked list pointed to
//  * by head.
//  */
// void print(Node* head);

// /**
//  * Deallocates the linked list nodes
//  */
// void dealloc(Node* head); 

Node* readList(const char* filename);
void print(Node* head);
void dealloc(Node* head);

// pred
struct IsEven {
    bool operator()(int x) const {
        return x % 2 == 0;  // ven numbers
 }
};

Node* readList(const char* filename) {
    Node* h = nullptr;
    ifstream ifile(filename);
    int v;
    if (!(ifile >> v)) return h;
    h = new Node(v, nullptr);
    Node* t = h;
    while (ifile >> v) {
   t->next = new Node(v, nullptr);
     t = t->next;}
    return h;}

void print(Node* head) {
    while (head) {
   cout << head->val << " ";
  head = head->next;  }
    cout << endl; }

void dealloc(Node* head) {
    Node* temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;} }

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1; }

    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    Node* smaller = nullptr;
    Node* larger = nullptr;
    int input;
    IsEven filter;  // Our predicate object

    cout << "Enter 1 for pivot operation or 2 for filter operation: ";
    cin >> input;

    if (input == 1) {
    llpivot(head, smaller, larger, 8);
  cout << "after pivoting, here is smaller list: ";
    print(smaller);
    cout << "after pivoting, here is larger list: ";
     print(larger);
     cout << "Remaining head list: ";
    print(head); } 
    else if (input == 2) {
        head = llfilter(head, filter);
    cout << "Updated head list after filter operation: ";
        print(head);}

    dealloc(smaller);
    dealloc(larger);
    dealloc(head);
    
    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <functional>
// #include "llrec.h"
// using namespace std;

// /**
//  * Reads integers (separated by whitespace) from a file
//  * into a linked list.
//  *
//  * @param[in] filename
//  *  The name of the file containing the data to read
//  * @return
//  *  Pointer to the linked list (or NULL if empty or the
//  *  file is invalid)
//  */
// Node* readList(const char* filename);

// /**
//  * Prints the integers in a linked list pointed to
//  * by head.
//  */
// void print(Node* head);

// /**
//  * Deallocates the linked list nodes
//  */
// void dealloc(Node* head);

// struct pred{
//   bool operator()(int x){
//     if(x%2 == 0){ return true;}
//     else{ return false;}
//   }
// };


// Node* readList(const char* filename)
// {
//     Node* h = NULL;
//     ifstream ifile(filename);
//     int v;
//     if( ! (ifile >> v) ) return h;
//     h = new Node(v, NULL);
//     Node *t = h;
//     while ( ifile >> v ) {
//         t->next = new Node(v, NULL);
//         t = t->next;
//     }
//     return h;
// }

// void print(Node* head)
// {
//     while(head) {
//         cout << head->val << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// void dealloc(Node* head)
// {
//     Node* temp;
//     while(head) {
//         temp = head->next;
//         delete head;
//         head = temp;
//     }
// }

// // -----------------------------------------------
// //   Add any helper functions or
// //   function object struct declarations
// // -----------------------------------------------



// int main(int argc, char* argv[]) {

  
//     if (argc < 2) {
//         cout << "Please provide an input file" << endl;
//         return 1;
//     }

//     // Read list from file
//     Node* head = readList(argv[1]);
//     cout << "Original list: ";
//     print(head);

//     // Declare and initialize pointers
//     Node* smaller = nullptr;
//     Node* larger = nullptr;
//     int input;
//     pred c;

//     cout << "Enter 1 for pivot operation or 2 for filter operation: ";
//     cin >> input;

//     if (input == 1) {
//         llpivot(head, smaller, larger, 8);

//         // Show results 
//         cout << "After pivoting, smaller list: ";
//         print(smaller);

//         cout << "After pivoting, larger list: ";
//         print(larger);

//         cout << "Remaining head list: ";
//         print(head); // also show to see that it doesnt have any node inside
//     } 
//     else if (input == 2) {
//         head = llfilter(head, c);

//         // Show result after filtering
//         cout << "Updated head list after filter operation: ";
//         print(head);
//     }

//     return 0;
// }