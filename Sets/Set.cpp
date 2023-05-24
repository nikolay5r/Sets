#include "Set.h"
#include "MyVector.hpp"
#include <limits>

void Set::attestElement(long element)
{
	if (element < INT_MIN || element > UINT_MAX)
	{
		throw std::invalid_argument("Invalid Element! Element is out of range for the set! Elements in set should be between 2^32-1 and -2^16+1");
	}
}
