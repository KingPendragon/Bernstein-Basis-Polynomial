#include <iostream>

#include <math.h>

#include "Polynomial.h"

using namespace std;

Polynomial Polynomial::getIndefiniteIntegral() const
{
	Polynomial Result;

	Result.fDegree = fDegree + 1;

	for (int i = Result.fDegree; i > 0; i--)
	{
		Result.fCoeffs[i] = fCoeffs[i - 1] / i;
	}
	return Result;
}

double Polynomial::operator()(double aX) const
{
	double sum = 0;

	for (int i = 0; i <= fDegree; i++)
	{
		sum += fCoeffs[i] * pow(aX, i);
	}
	return sum;
}

Polynomial Polynomial::getDerivative() const
{
	Polynomial Result;

	if (fDegree >= 1)
	{
		Result.fDegree = fDegree - 1;

		for (int i = 0; i < fDegree; i++)
		{
			Result.fCoeffs[i] = (i + 1) * fCoeffs[i + 1];
		}
	}
		return Result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
	Polynomial indefinitePolyNoms = getIndefiniteIntegral();

	double xLow = 0;
	double xHigh = 0;

	for (int i = 0; i <= indefinitePolyNoms.fDegree; i++)
	{
		xLow += indefinitePolyNoms.fCoeffs[i] * pow(aXLow, i);
	}

	for (int i = 0; i <= indefinitePolyNoms.fDegree; i++)
	{
		xHigh += indefinitePolyNoms.fCoeffs[i] * pow(aXHigh, i);
	}

	return xHigh - xLow;
}