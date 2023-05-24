#include "CriteriaSet.h"
#include "Set.h"

CriteriaSet::CriteriaSet(MyVector<long> criteriaElements, bool (*pred)(long elementToCheck, long criteria)) : criteriaElements(criteriaElements), pred(pred)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(size_t numberOfCriteriaElements, long* criteriaElements, bool (*pred)(long elementToCheck, long criteriaElement)) : pred(pred)
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(long criteriaElement, bool (*pred)(long elementToCheck, long criteriaElement)) : pred(pred)
{
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

bool CriteriaSet::has(long element) const
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		if (!(*pred)(element, criteriaElements[i]))
		{
			return false;
		}
	}
	return true;
}
