#include "Combination.h"
#include "BernsteinBasisPolynomial.h"
#include <cmath>

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN)
{
	fFactor = Combination(aN, aV);
}

double BernsteinBasisPolynomial::operator()(double aX) const
{
	unsigned int aN = this->fFactor.getN();
	unsigned int aV = this->fFactor.getK();

	return fFactor() * pow(aX, aV) * pow(1 - aX, aN - aV);
}


