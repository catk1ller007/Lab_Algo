#ifndef Generator_H
#define Generator_H

#include <iostream>
#include <random>

class IntegerGenerator {
private:
    std::random_device rd;  
    std::mt19937 gen;      
    std::uniform_int_distribution<int64_t> dis; 

public:
    IntegerGenerator(size_t min, size_t max) : gen(rd()), dis(min, max) {}

    int64_t generate() { return dis(gen); }
 
};

#endif // Generator_H

