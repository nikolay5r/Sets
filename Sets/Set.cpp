#include "Set.h"
#include "MyVector.hpp"
#include <limits>

void Set::attestElement(long element) const
{
	if (element < INT_MIN || element > UINT_MAX)
	{
		throw std::invalid_argument("Invalid Element! Element is out of range for the set! Elements in set should be between 2^32-1 and -2^16+1");
	}
}

long Set::next() const
{
	currentElement++;
	for (; currentElement < UINT_MAX; currentElement++)
	{
		if (has(currentElement))
		{
			return currentElement;
		}
	}
}

long Set::prev() const
{
	currentElement--;
	for (; currentElement > INT_MIN; currentElement--)
	{
		if (has(currentElement))
		{
			return currentElement;
		}
	}
}

void Set::print(long a, long b) const
{
	attestElement(a);
	attestElement(b);
	if (a > b)
	{
		throw std::logic_error("First arg must be smaller than second arg!");
	}
	int count = 0;
	for (long i = a; i < b; i++)
	{
		if (has(i))
		{
			count++;
			std::cout << i << " ";
		}
	}

	if (count == 0)
	{
		std::cout << "No elements found...";
	}

	std::cout << std::endl;
}