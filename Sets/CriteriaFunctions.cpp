#include "CriteriaFunctions.h"
#include "MyVector.hpp"

bool criteriaFunctions::isEqualTo(const MyVector<long long>& criteriaElements, long long element)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		if (element == criteriaElements[i])
		{
			return true;
		}
	}

	return false;
}

bool criteriaFunctions::isNotDivisibleTo(const MyVector<long long>& criteriaElements, long long element)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		if (element % criteriaElements[i] == 0)
		{
			return false;
		}
	}

	return true;
}

bool criteriaFunctions::isDivisibleTo(const MyVector<long long>& criteriaElements, long long element)
{
	return !isNotDivisibleTo(criteriaElements, element);
}
