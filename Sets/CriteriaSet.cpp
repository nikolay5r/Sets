#include "CriteriaSet.h"
#include "Set.h"

Set* CriteriaSet::clone() const
{
	return new CriteriaSet(*this);
}

CriteriaSet::CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), const MyVector<long long>& criteriaElements)
	: criteriaElements(criteriaElements), pred(pred)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), size_t numberOfCriteriaElements, const long long* criteriaElements)
	: pred(pred), criteriaElements(numberOfCriteriaElements)
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), long long criteriaElement)
	: pred(pred), criteriaElements(1)
{
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

bool CriteriaSet::has(long long element) const
{
	return (*pred)(criteriaElements, element);
}
