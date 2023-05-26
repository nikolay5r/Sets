#pragma once
#include "Set.h"
#include "MyVector.hpp"

class CriteriaSet : public Set
{
private:
	bool (*pred)(const MyVector<long long>& criteriaElements, long long element) = nullptr;
	MyVector<long long> criteriaElements;

public:
	CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), const MyVector<long long>& criteriaElements);
	CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), size_t numberOfCriteriaElements, const long long* criteriaElements);
	CriteriaSet(bool (*pred)(const MyVector<long long>& criteriaElements, long long element), long long criteriaElement);

	bool has(long long element) const override;
	Set* clone() const override;

	~CriteriaSet() = default;
};

namespace criteriaFunctions
{
	bool isEqualTo(const MyVector<long long>& criteriaElements, long long element);
	bool isNotDivisibleTo(const MyVector<long long>& criteriaElements, long long element);
	bool isDivisibleTo(const MyVector<long long>& criteriaElements, long long element);
	bool otherFunction(const MyVector<long long>& criteriaElements, long long element);
}