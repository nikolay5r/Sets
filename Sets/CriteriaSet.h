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

public:
	CriteriaSet(const MyVector<long long>& criteriaElements, bool (*pred)(long long elementToCheck, long long criteriaElement));
	CriteriaSet(size_t numberOfCriteriaElements, const long long* criteriaElements, bool (*pred)(long long elementToCheck, long long criteriaElement));
	CriteriaSet(long long criteriaElement, bool (*pred)(long long elementToCheck, long long criteriaElement));

	bool has(long long element) const override;
	Set* clone() const override;

	~CriteriaSet() = default;
};

