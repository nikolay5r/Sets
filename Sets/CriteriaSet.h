#pragma once
#include "Set.h"
#include "MyVector.hpp"

class CriteriaSet : public Set
{
private:
	bool (*pred)(long elementToCheck, long criteriaElement) = nullptr;
	MyVector<long> criteriaElements;

public:
	CriteriaSet(MyVector<long> criteriaElements, bool (*pred)(long elementToCheck, long criteriaElement));
	CriteriaSet(size_t numberOfCriteriaElements, long* criteriaElements, bool (*pred)(long elementToCheck, long criteriaElement));
	CriteriaSet(long criteriaElement, bool (*pred)(long elementToCheck, long criteriaElement));

	bool has(long element) const override;
	Set* clone() const override;

	~CriteriaSet() = default;
};

