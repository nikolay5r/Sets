#include "CriteriaSet.h"
#include "Set.h"

void CriteriaSet::attestCriteriaElement(long element)
{
	if (element < INT_MIN || element > UINT_MAX)
	{
		throw std::invalid_argument("Invalid element found in the criteria elements! Criteria elements must be smaller than 2^32 - 1 and larger than -2^16!");
	}
}

void CriteriaSet::attestElementWithCriteriaFunc(long element)
{
	if (!canContain(element))
	{
		throw std::invalid_argument("The element you are trying to add is invalid! The element does not meet the criteria!");
	}
}

CriteriaSet::CriteriaSet(MyVector<long> criteriaElements, bool (*pred)(long element)) : Set()
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestCriteriaElement(criteriaElements[i]);
	}
	this->pred = pred;
}

CriteriaSet::CriteriaSet(size_t numberOfCriteriaElements, long* criteriaElements, bool (*pred)(long element)) : Set()
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestCriteriaElement(criteriaElements[i]);
	}
	this->pred = pred;
}

void CriteriaSet::add(long element)
{
	attestElement(element);
	attestElementWithCriteriaFunc(element);

	if (!elements.contains(element))
	{
		elements.push_back(element);
	}
}

void CriteriaSet::remove(long element)
{
	if (!elements.contains(element))
	{
		throw std::invalid_argument("The element you are trying to remove does not exists in the set!");
	}

	size_t size = elements.size();
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] == element)
		{
			elements.pop_at(i);
			break;
		}
	}
}

bool CriteriaSet::canContain(long element)
{
	return (*pred)(element);
}