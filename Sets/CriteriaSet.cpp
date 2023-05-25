#include "CriteriaSet.h"
#include "Set.h"

Set* CriteriaSet::clone() const
{
	return new CriteriaSet(*this);
}

CriteriaSet::CriteriaSet(bool (*pred)(long long elementToCheck, long long criteria), const MyVector<long long>& criteriaElements) : criteriaElements(criteriaElements), pred(pred)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(bool (*pred)(long long elementToCheck, long long criteriaElement), size_t numberOfCriteriaElements, const long long* criteriaElements) : pred(pred)
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(bool (*pred)(long long elementToCheck, long long criteriaElement), long long criteriaElement) : pred(pred)
{
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

CriteriaSet::CriteriaSet(Criteria criteria, long long criteriaElement) : criteria(criteria)
{
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

void CriteriaSet::assignCriteriaFunction(Criteria criteria)
{
	switch (criteria)
	{
	case Criteria::Equal:
		pred = criteria::isEqualTo;
		break;
	case Criteria::Divisible:
		pred = criteria::isDivisibleTo;
		break;
	case Criteria::NotDivisible:
		break;
	default:
		pred = criteria::isNotDivisibleTo;
		break;
	}
}

CriteriaSet::CriteriaSet(Criteria criteria, const MyVector<long long>& criteriaElements) : criteriaElements(criteriaElements), criteria(criteria)
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(Criteria criteria, size_t numberOfCriteriaElements, const long long* criteriaElements) : criteria(criteria)
{
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
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

bool criteria::otherFunction(long long elementToCheck, long long criteriaElement)
{
	return true;
}
