#include "SortableIntVector.h"

#include <stdexcept>

using namespace std;

SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : 
	IntVector( aArrayOfIntegers, aNumberOfElements)
{}

void SortableIntVector::sort(Comparable aOrderFunction)
{

    for (int i = 0; i < size() - 1; i++)
    { 
        for (int j = size() - 1; j >= i + 1; j--)
        {
            if (aOrderFunction(get(j), get(j - 1)))
                swap(j, j - 1);

        }
    }
}


