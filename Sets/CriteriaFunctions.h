#pragma once
#include "MyVector.hpp"

namespace criteriaFunctions
{
	bool isEqualTo(const MyVector<long long>& criteriaElements, long long element);
	bool isNotDivisibleTo(const MyVector<long long>& criteriaElements, long long element);
	bool isDivisibleTo(const MyVector<long long>& criteriaElements, long long element);
}
