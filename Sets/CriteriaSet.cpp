#include "CriteriaSet.h"
#include "Set.h"

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