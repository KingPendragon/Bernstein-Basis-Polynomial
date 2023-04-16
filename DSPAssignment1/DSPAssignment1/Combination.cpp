#include "Combination.h"

Combination::Combination(size_t aN, size_t aK)
{
    fN = aN;
    fK = aK;
}

size_t Combination::getN() const
{
    return fN;
}

size_t Combination::getK() const
{
    return fK;
}

unsigned long long Combination::operator()() const
{
    unsigned long long Numerator = fN;
    unsigned long long Denominator = fK;
    unsigned long long Result;

    if (fK == 0)
    {
        // If the denominator == 0 then the result
        // would resolve to x/0 = 0; 
        Result = 1;
    }
    else
    {
        for (unsigned int i = 1; i <= fK - 1; i++)
        {
            Numerator = Numerator * (fN - i);
        }
        for (unsigned int j = 1; j < fK; j++)
        {
            Denominator = Denominator * j;
        }
        Result = Numerator / Denominator;
    }
    return Result;
}