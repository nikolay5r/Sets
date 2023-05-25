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
	assignCriteriaFunction(criteria);
	attestElement(criteriaElement);
	criteriaElements.push_back(criteriaElement);
}

CriteriaSet::CriteriaSet(Criteria criteria, const MyVector<long long>& criteriaElements) : criteriaElements(criteriaElements), criteria(criteria)
{
	size_t size = criteriaElements.size();
	assignCriteriaFunction(criteria);
	for (size_t i = 0; i < size; i++)
	{
		attestElement(criteriaElements[i]);
	}
}

CriteriaSet::CriteriaSet(Criteria criteria, size_t numberOfCriteriaElements, const long long* criteriaElements) : criteria(criteria)
{
	assignCriteriaFunction(criteria);
	for (size_t i = 0; i < numberOfCriteriaElements; i++)
	{
		attestElement(criteriaElements[i]);
		this->criteriaElements.push_back(criteriaElements[i]);
	}
}

void CriteriaSet::assignCriteriaFunction(Criteria criteria)
{
	switch (criteria)
	{
	case Criteria::Equal:
		pred = criteriaFunctions::isEqualTo;
		break;
	case Criteria::Divisible:
		pred = criteriaFunctions::isDivisibleTo;
		break;
	case Criteria::NotDivisible:
		pred = criteriaFunctions::isNotDivisibleTo;
		break;
	default:
		pred = criteriaFunctions::otherFunction;
		break;
	}
}

bool CriteriaSet::has(long long element) const
{
	size_t size = criteriaElements.size();
	for (size_t i = 0; i < size; i++)
	{
		if ((*pred)(element, criteriaElements[i]) && criteria != Criteria::NotDivisible)
		{
			return true;
		}
		else if (!(*pred)(element, criteriaElements[i]) && criteria == Criteria::NotDivisible)
		{
			return false;
		}
	}

	return criteria == Criteria::NotDivisible;
}

bool criteriaFunctions::isEqualTo(long long elementToCheck, long long criteriaElement)
{
	return elementToCheck == criteriaElement;
}

bool criteriaFunctions::isNotDivisibleTo(long long elementToCheck, long long criteriaElement)
{
	return elementToCheck % criteriaElement != 0;
}

bool criteriaFunctions::isDivisibleTo(long long elementToCheck, long long criteriaElement)
{
	return !isNotDivisibleTo(elementToCheck, criteriaElement);
}

bool criteriaFunctions::otherFunction(long long elementToCheck, long long criteriaElement)
{
	return true;
}
