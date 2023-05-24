#include "CriteriaSet.h"
#include "Set.h"

Set* CriteriaSet::clone() const
{
	return new CriteriaSet(*this);
}

CriteriaSet::CriteriaSet(const MyVector<long long>& criteriaElements, bool (*pred)(long long elementToCheck, long long criteria)) : criteriaElements(criteriaElements), pred(pred)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(size_t numberOfCriteriaElements, const long long* criteriaElements, bool (*pred)(long long elementToCheck, long long criteriaElement)) : pred(pred)
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(long long criteriaElement, bool (*pred)(long long elementToCheck, long long criteriaElement)) : pred(pred)
{
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

bool CriteriaSet::has(long long element) const
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		if ((*pred)(element, criteriaElements[i]))
		{
			return true;
		}
	}
	return false;
}
