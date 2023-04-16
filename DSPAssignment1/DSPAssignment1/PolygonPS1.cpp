#include "Polygon.h"

#include <stdexcept>

using namespace std;

float Polygon::getSignedArea() const
{
    float Result = 0;
	int k = fNumberOfVertices - 1;

		for (size_t i = 0; i < fNumberOfVertices; i++)
		{
			Result += ((fVertices[k].getX() + fVertices[i].getX()) * (fVertices[k].getY() + fVertices[i].getY()));
			k - i;
		}
		
	return Result;
}
