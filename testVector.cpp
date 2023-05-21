// test.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "customVector.h"

TEST_CASE("Construction and Initialization")
{
    SECTION("Default construction initializes the vector correctly")
    {
        customVector<int> vec;
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.empty());
    }

    SECTION("Construction with size and value initializes the vector correctly")
    {
        customVector<int> vec(5, 42);
        REQUIRE(vec.size() == 5);
        for (int i = 0; i < 5; ++i)
        {
            REQUIRE(vec[i] == 42);
        }
    }

    SECTION("Construction with initializer list initializes the vector correctly")
    {
        customVector<int> vec = {1, 2, 3, 4, 5};
        REQUIRE(vec.size() == 5);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec[2] == 3);
        REQUIRE(vec[3] == 4);
        REQUIRE(vec[4] == 5);
    }

    SECTION("Destructor frees the allocated memory")
    {
        customVector<int>* vecPtr = new customVector<int>(10, 7);
        REQUIRE(vecPtr->size() == 10);
        REQUIRE(vecPtr->getCapacity() == 10);
        delete vecPtr;

    }
}

TEST_CASE("Element Access")
{
    customVector<int> vec = {1, 2, 3, 4, 5};

    SECTION("Accessing elements using at() returns the correct element")
    {
        REQUIRE(vec.at(0) == 1);
        REQUIRE(vec.at(2) == 3);
        REQUIRE(vec.at(4) == 5);
        
    }

    SECTION("Accessing elements using operator[] returns the correct element")
    {
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[2] == 3);
        REQUIRE(vec[4] == 5);
    }

    SECTION("Front returns the first element")
    {
        REQUIRE(vec.front() == 1);
    }

    SECTION("Back returns the last element")
    {
        REQUIRE(vec.back() == 5);
    }

}

TEST_CASE("Capacity and Size")
{
    SECTION("Empty returns true for an empty vector")
    {
        customVector<int> vec;
        REQUIRE(vec.empty());
    }

    SECTION("Empty returns false for a non-empty vector")
    {
        customVector<int> vec = {1, 2, 3};
        REQUIRE_FALSE(vec.empty());
    }

    SECTION("Size returns the correct number of elements")
    {
        customVector<int> vec = {1, 2, 3, 4, 5};
        REQUIRE(vec.size() == 5);
    }

    SECTION("Max size returns the maximum possible number of elements")
    {
        customVector<int> vec;
        REQUIRE(vec.max_size() > 0);
    }

    SECTION("Reserve increases the capacity of the vector")
    {
        customVector<int> vec;
        vec.reserve(10);
        REQUIRE(vec.getCapacity() >= 10);
    }

    SECTION("Capacity returns the current capacity of the vector")
    {
        customVector<int> vec;
        vec.reserve(20);
        REQUIRE(vec.getCapacity() >= 20);
    }

    SECTION("Shrink to fit reduces memory usage")
    {
        customVector<int> vec = {1, 2, 3};
        vec.reserve(10);
        size_t initialCapacity = vec.getCapacity();
        vec.shrink_to_fit();
        REQUIRE(vec.getCapacity() <= initialCapacity);
    }
}

TEST_CASE("Modifiers")
{
    customVector<int> vec = {1, 2, 3};

    SECTION("push_back tests")
    {
        customVector<int> myVector;
        myVector.push_back(5);
        myVector.push_back(6);
        myVector.push_back(7);
        myVector.push_back(8);
        myVector.push_back(9);
        REQUIRE(myVector.size() == 5);
        REQUIRE(myVector.back() == 9);
        REQUIRE(myVector.front() == 5);


    }

    SECTION("Clear empties the vector and sets size to zero")
    {
        vec.clear();
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.empty());
    }

    SECTION("Emplace constructs elements in-place at the specified position")
    {
        vec.emplace(vec.begin() + 1, 99);
        REQUIRE(vec[1] == 99);
        REQUIRE(vec[2] == 2);
    }

    SECTION("Push back adds an element to the end")
    {
        vec.push_back(10);
        vec.push_back(6);

        REQUIRE(vec.size() == 5);
        REQUIRE(vec.back() == 6);
    }

    SECTION("Resize changes the number of elements")
    {
        vec.resize(2);
        REQUIRE(vec.size() == 2);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
    }
}

TEST_CASE("Comparison and Non-member Functions")
{
    customVector<int> vec1 = {1, 2, 3};
    customVector<int> vec2 = {1, 2, 3};
    customVector<int> vec3 = {4, 5, 6};

    SECTION("Equality comparison operator")
    {
        REQUIRE(vec1 == vec2);
        REQUIRE_FALSE(vec1 == vec3);
    }

    SECTION("Inequality comparison operator")
    {
        REQUIRE_FALSE(vec1 != vec2);
        REQUIRE(vec1 != vec3);
    }

    SECTION("Less than comparison operator")
    {
        REQUIRE_FALSE(vec1 < vec2);
        REQUIRE(vec1 < vec3);
    }

    SECTION("Less than or equal to comparison operator")
    {
        REQUIRE(vec1 <= vec2);
        REQUIRE(vec1 <= vec3);
    }

    SECTION("Greater than comparison operator")
    {
        REQUIRE_FALSE(vec1 > vec2);
        REQUIRE_FALSE(vec1 > vec3);
    }

    SECTION("Greater than or equal to comparison operator")
    {
        REQUIRE(vec1 >= vec2);
        REQUIRE_FALSE(vec1 >= vec3);
    }
}


// // Compile & run:
// // - g++ -std=c++11 -Wall functions.cpp test.cpp -o test && ./test
