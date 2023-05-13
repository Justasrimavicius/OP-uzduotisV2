// test.cpp

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "functions.h"

int Factorial( int number ) {
   return number <= 1 ? number : Factorial( number - 1 ) * number;
}

TEST_CASE( "Factorial of 0 is 1 (fail)", "[single-file]" ) {
    REQUIRE( Factorial(0) == 1 );
}

TEST_CASE( "Generate file line count test", "[single-file]" ) {
    generateFile("1000", "10");

    std::ifstream file("studentai1000.txt");

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineCount++;
    }
    cout << lineCount << endl;
    // Assert that the line count matches the expected value
    REQUIRE(lineCount == 1001);


}

// Compile & run:
// - g++ -std=c++11 -Wall functions.cpp test.cpp -o test
// ./test
