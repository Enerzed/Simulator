#pragma once
#include <random>

class Random
{
public:
    std::random_device rd;
    
    int min;
    int max;

    Random()
    {

    }

    int generate(int min, int max)
    {
        std::mt19937 generate(rd());
        std::uniform_int_distribution<> distribute(min, max);
        return distribute(generate);
    }
};

