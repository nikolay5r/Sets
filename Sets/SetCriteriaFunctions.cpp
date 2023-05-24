#include "SetCriteriaFunctions.h"


bool criteria::isEqualTo(long long elementToCheck, long long criteriaElement)
{
	return elementToCheck == criteriaElement;
}

bool criteria::isNotDivisibleTo(long long elementToCheck, long long criteriaElement)
{
	return elementToCheck % criteriaElement != 0;
}

bool criteria::isDivisibleTo(long long elementToCheck, long long criteriaElement)
{
	return !isNotDivisibleTo(elementToCheck, criteriaElement);
}