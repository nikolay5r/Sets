#include "Set.h"
#include "MyVector.hpp"
#include <limits>

size_t Set::size() const
{
	return elements.size();
}

bool Set::isEmpty() const
{
	return elements.isEmpty();
}

bool Set::has(long element) const
{
	return elements.contains(element);
}

bool Set::isElementValid(long element) const
{
	return element < UINT_MAX&& element > INT_MIN;
}
