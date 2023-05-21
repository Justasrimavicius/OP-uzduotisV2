#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

#include <cstddef> // For std::size_t
#include <memory>  // For std::allocator
#include <iterator>  // Add this include

template <typename T, typename Allocator = std::allocator<T>>
class customVector {
public:
    using iterator = T*;
    using value_type = T;
    using allocator_type = Allocator;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

    // Default constructor
    customVector() : elements(nullptr), numElements(0), capacity(0) {}

    // Constructor with size
    explicit customVector(size_type count) : numElements(count), capacity(count) {
        elements = allocator.allocate(count);
        for (size_type i = 0; i < count; ++i) {
            allocator.construct(&elements[i]);
        }
    }
    // Constructor with initializer list
    customVector(std::initializer_list<T> initList) : elements(nullptr), numElements(0), capacity(0) {
        reserve(initList.size());
        for (const auto& element : initList) {
            push_back(element);
        }
    }
    // Constructor with size and value
    explicit customVector(size_type count, const value_type& value)
        : numElements(count), capacity(count), elements(nullptr) {
        elements = allocator.allocate(count);
        for (size_type i = 0; i < count; ++i) {
            allocator.construct(&elements[i], value);
        }
    }

    // Destructor
    ~customVector() {
        clear();
        allocator.deallocate(elements, capacity);
    }

    // Size of the vector
    size_type size() const {
        return numElements;
    }

    // Check if the vector is empty
    bool empty() const {
        return numElements == 0;
    }

    // Access element using operator[]
    reference operator[](size_type index) {
        return elements[index];
    }

    // Access element using operator[] (const version)
    const_reference operator[](size_type index) const {
        return elements[index];
    }

    // Access element with bounds checking
    reference at(size_type index) {
        if (index >= numElements) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    // Access element with bounds checking (const version)
    const_reference at(size_type index) const {
        if (index >= numElements) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    // Access the first element
    reference front() {
        return elements[0];
    }

    // Access the first element (const version)
    const_reference front() const {
        return elements[0];
    }

    // Access the last element
    reference back() {
        return elements[numElements - 1];
    }

    // Access the last element (const version)
    const_reference back() const {
        return elements[numElements - 1];
    }

    // Direct access to the underlying array
    pointer data() {
        return elements;
    }

    // Direct access to the underlying array (const version)
    const_pointer data() const {
        return elements;
    }
    // Capacity getter
    size_type getCapacity() const {
        return capacity;
    }

    // Function to get the maximum possible number of elements
    size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }
    iterator end() {
        return elements + size();
    }

    // Function to reserve capacity
    void reserve(size_type newCapacity) {
        if (newCapacity <= capacity) {
            return;
        }

        T* newElements = allocator.allocate(newCapacity);

        for (size_type i = 0; i < numElements; ++i) {
            allocator.construct(&newElements[i], std::move(elements[i]));
            allocator.destroy(&elements[i]);
        }

        allocator.deallocate(elements, capacity);

        elements = newElements;  // Update the elements pointer
        capacity = newCapacity;
    }

    // Function to reduce memory usage to fit the current size
    void shrink_to_fit() {
        if (numElements < capacity) {
            T* newElements = allocator.allocate(numElements);

            for (size_type i = 0; i < numElements; ++i) {
                allocator.construct(&newElements[i], std::move(elements[i]));
                allocator.destroy(&elements[i]);
            }

            allocator.deallocate(elements, capacity);

            elements = newElements;
            capacity = numElements;
        }
    }
    iterator begin() {
        return elements;
    }

    void clear() {
        for (size_type i = 0; i < numElements; ++i) {
            allocator.destroy(&elements[i]);
        }
        numElements = 0;
    }

    template <typename... Args>
    iterator emplace(iterator position, Args&&... args) {
        // Calculate the index corresponding to the position iterator
        difference_type index = position - elements;

        // Check if the vector needs to be resized
        if (size() == capacity) {
            resize(capacity * 2); // Increase capacity
        }

        // Move the elements after the insert position to make space for the new element
        std::move_backward(elements + index, elements + size(), elements + size() + 1);

        // Construct the new element at the insert position
        allocator.construct(elements + index, std::forward<Args>(args)...);

        // Return the iterator pointing to the inserted element
        return position;
    }
    iterator insert(iterator position, const T& value) {
        size_type index = position - begin();

        if (numElements == capacity) {
            size_type newCapacity = capacity == 0 ? 1 : capacity * 2;
            reserve(newCapacity);
        }

        // Move elements to make space for the new element
        std::move_backward(elements + index, elements + numElements, elements + numElements + 1);

        // Construct the new element at the specified position
        allocator.construct(&elements[index], value);
        ++numElements;

        return begin() + index;
    }

    iterator erase(iterator position) {
        size_type index = position - begin();

        // Destroy the element to be erased
        allocator.destroy(elements + index);

        // Move elements to fill the gap
        std::move(begin() + index + 1, end(), begin() + index);

        --numElements;

        return begin() + index;
    }

    void push_back(const T& value) {
        if (numElements == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }

        allocator.construct(&elements[numElements], value);
        ++numElements;
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        if (numElements == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }

        allocator.construct(&elements[numElements], std::forward<Args>(args)...);
        ++numElements;
    }

    void pop_back() {
        if (numElements > 0) {
            allocator.destroy(&elements[numElements - 1]);
            --numElements;
        }
    }

    void resize(size_type newSize) {
        if (newSize < numElements) {
            for (size_type i = newSize; i < numElements; ++i) {
                allocator.destroy(&elements[i]);
            }
        } else if (newSize > numElements) {
            reserve(newSize * 2);
            for (size_type i = numElements; i < newSize; ++i) {
                allocator.construct(&elements[i], T{});
            }
        }

        numElements = newSize;
    }

    void swap(customVector& other) {
        std::swap(elements, other.elements);
        std::swap(numElements, other.numElements);
        std::swap(capacity, other.capacity);
        std::swap(allocator, other.allocator);
    }

    bool operator==(const customVector& other) const {
    if (numElements != other.numElements) {
        return false;
    }
    
    for (size_type i = 0; i < numElements; ++i) {
        if (elements[i] != other.elements[i]) {
            return false;
        }
    }
    
    return true;
    }

    bool operator!=(const customVector& other) const {
        return !(*this == other);
    }

    bool operator<(const customVector& other) const {
        size_type minSize = std::min(numElements, other.numElements);
        
        for (size_type i = 0; i < minSize; ++i) {
            if (elements[i] < other.elements[i]) {
                return true;
            } else if (elements[i] > other.elements[i]) {
                return false;
            }
        }
        
        return numElements < other.numElements;
    }

    bool operator<=(const customVector& other) const {
        return (*this == other) || (*this < other);
    }

    bool operator>(const customVector& other) const {
        return !(*this <= other);
    }

    bool operator>=(const customVector& other) const {
        return !(*this < other);
    }



private:
    pointer elements;
    size_type numElements;
    size_type capacity;
    allocator_type allocator;

};

#endif // CUSTOM_VECTOR_H
