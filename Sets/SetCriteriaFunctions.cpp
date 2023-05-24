#include "SetCriteriaFunctions.h"


bool criteria::isEqualTo(long elementToCheck, long criteriaElement)
{
	return elementToCheck == criteriaElement;
}

bool criteria::isNotDividableTo(long elementToCheck, long criteriaElement)
{
	return elementToCheck % criteriaElement != 0;
}

bool criteria::isDividableTo(long elementToCheck, long criteriaElement)
{
	return !isNotDividableTo(elementToCheck, criteriaElement);
}