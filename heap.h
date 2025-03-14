#ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <stdexcept>
#include <vector>

/**
 * @brief A templated Heap class that supports both min-heap and max-heap using a comparator.
 *
 * @tparam T The type of elements stored in the heap.
 * @tparam PComparator The comparator used to determine priority (default: std::less<T> for min-heap).
 */
template <typename T, typename PComparator = std::less<T>>
class Heap {
public:
    /**
     * @brief Construct a new Heap object.
     *
     * @param m The ary-ness of the heap tree (defaults to 2).
     * @param c A binary predicate functor that determines priority between two elements.
     */
    Heap(int m = 2, PComparator c = PComparator());

    /**
     * @brief Destroy the Heap object.
     */
    ~Heap();

    /**
     * @brief Push an item onto the heap.
     *
     * @param item The item to insert into the heap.
     */
    void push(const T& item);

    /**
     * @brief Returns the top (highest priority) item without removing it.
     *
     * @return T const& The top element in the heap.
     * @throw std::underflow_error if the heap is empty.
     */
    T const& top() const;

    /**
     * @brief Removes the top priority item from the heap.
     *
     * @throw std::underflow_error if the heap is empty.
     */
    void pop();

    /**
     * @brief Returns true if the heap is empty.
     */
    bool empty() const;

    /**
     * @brief Returns the number of elements in the heap.
     */
    size_t size() const;

private:
    std::vector<T> heap_;  //
    int m_;               
    PComparator comp_;     //The comparator used to for heap order.

    /**
     * @brief Helper function to maintain the heap property after insertion.
     *
     * @param idx Index of the newly inserted element.
     */
    void heapifyUp(size_t idx);

    /**
     * @brief Helper function to maintain the heap property after removal.
     *
     * @param idx Index of the element to heapify down.
     */
    void heapifyDown(size_t idx);
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

// Des
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// Push  into the heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) { heap_.push_back(item);
    heapifyUp(heap_.size() - 1);
}

// Return the top 
template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const {
    if (empty()) {
        throw std::underflow_error("Heap is empty");
    }
    return heap_[0];
}

// Remove the top 
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
    if (empty()) {throw std::underflow_error("Heap is empty");}
    std::swap(heap_[0], heap_.back());
    heap_.pop_back();
    if (!empty()) {
        heapifyDown(0);
    }
}

// Check if  heap is empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return heap_.empty();}

// Return size of the heap
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return heap_.size();
}

// Heapify up to maintain heap order
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t idx) {
    if (idx == 0) return;
    size_t parent = (idx - 1) / m_;
    if (comp_(heap_[idx], heap_[parent])) {
      //swap
        std::swap(heap_[idx], heap_[parent]);
        heapifyUp(parent);
    }
}

// Heapify down to maintain heap order
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t idx) {
    size_t best = idx;
    for (int i = 1; i <= m_; ++i) { size_t child = m_ * idx + i;
        if (child < heap_.size() && comp_(heap_[child], heap_[best])) {
   best = child;}
    }
    if (best != idx) {
        std::swap(heap_[idx], heap_[best]);
        heapifyDown(best);
    }
}

#endif