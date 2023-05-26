#include "CriteriaSet.h"
#include "Set.h"

Set* CriteriaSet::clone() const
{
	return new CriteriaSet(*this);
}

CriteriaSet::CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), const MyVector<long long>& criteriaElements) : criteriaElements(criteriaElements), pred(pred)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), size_t numberOfCriteriaElements, const long long* criteriaElements) : pred(pred)
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), long long criteriaElement) : pred(pred)
{
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

bool CriteriaSet::has(long long element) const
{
	return (*pred)(criteriaElements, element);
}

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

bool criteriaFunctions::otherFunction(const MyVector<long long>& criteriaElements, long long element)
{
	return true;
}
