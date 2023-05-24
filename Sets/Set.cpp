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

void Set::attestElement(long element) const
{
	if (element < INT_MIN || element > UINT_MAX)
	{
		throw std::invalid_argument("Element you are trying to add is out of range for the set!");
	}
}
