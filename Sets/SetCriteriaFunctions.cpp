#include "SetCriteriaFunctions.h"


bool criteria::isEqualTo(long elementToCheck, long criteriaElement)
{
	return elementToCheck == criteriaElement;
}

bool criteria::isNotDivisibleTo(long elementToCheck, long criteriaElement)
{
	return elementToCheck % criteriaElement != 0;
}

bool criteria::isDivisibleTo(long elementToCheck, long criteriaElement)
{
	return !isNotDivisibleTo(elementToCheck, criteriaElement);
}