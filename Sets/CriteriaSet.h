#pragma once
#include "Set.h"
#include "MyVector.hpp"

enum class Criteria
{
	Equal,
	Divisible,
	NotDivisible,
	Other
};

class CriteriaSet : public Set
{
private:
	bool (*pred)(long long elementToCheck, long long criteriaElement) = nullptr;
	Criteria criteria = Criteria::Other;
	MyVector<long long> criteriaElements;

	void assignCriteriaFunction(Criteria criteria);

public:
	CriteriaSet(bool (*pred)(long long elementToCheck, long long criteriaElement), const MyVector<long long>& criteriaElements);
	CriteriaSet(bool (*pred)(long long elementToCheck, long long criteriaElement), size_t numberOfCriteriaElements, const long long* criteriaElements);
	CriteriaSet(bool (*pred)(long long elementToCheck, long long criteriaElement), long long criteriaElement);

	CriteriaSet(Criteria criteria, const MyVector<long long>& criteriaElements);
	CriteriaSet(Criteria criteria, size_t numberOfCriteriaElements, const long long* criteriaElements);
	CriteriaSet(Criteria criteria, long long criteriaElement);

	bool has(long long element) const override;
	Set* clone() const override;

	~CriteriaSet() = default;
};

namespace criteria
{
	bool isEqualTo(long long elementToCheck, long long criteriaElement);
	bool isNotDivisibleTo(long long elementToCheck, long long criteriaElement);
	bool isDivisibleTo(long long elementToCheck, long long criteriaElement);
	bool otherFunction(long long elementToCheck, long long criteriaElement);
}