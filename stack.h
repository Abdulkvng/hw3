#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
};

template <typename T>
Stack<T>::Stack() {}

template <typename T>
Stack<T>::~Stack() {}

// if size is equal to zero
template <typename T>
bool Stack<T>::empty() const {
    return this->size() == 0;
}

// size vector included
template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

// use vector property of pushing back
template <typename T>
void Stack<T>::push(const T& item) {
    std::vector<T>::push_back(item);
}

// using vector property
template <typename T>
void Stack<T>::pop() {
    if (this->empty()) {
        throw std::underflow_error("Vector is empty");
    } else {
        std::vector<T>::pop_back();
    }
}

template <typename T>
const T& Stack<T>::top() const {
    if (this->empty()) {
        throw std::underflow_error("Vector is empty");
    }
    return std::vector<T>::back();
}

#endif
