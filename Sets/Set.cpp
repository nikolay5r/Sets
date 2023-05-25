#include "Set.h"
#include "MyVector.hpp"
#include <limits>

void Set::attestElement(long long element) const
{
	if (element < INT_MIN || element > UINT_MAX)
	{
		throw std::out_of_range("Invalid Element! Element is out of range for the set! Elements in set should be between 2^32-1 and -2^16+1");
	}
}

long long Set::next() const
{
	currentElement++;
	for (long long i = currentElement; i < UINT_MAX; i++)
	{
		if (has(i))
		{
			currentElement = i;
			return currentElement;
		}
	}
}

long long Set::prev() const
{
	currentElement--;
	for (long long i = currentElement; i > INT_MIN; i--)
	{
		if (has(i))
		{
			currentElement = i;
			return currentElement;
		}
	}
}

void Set::print(long long a, long long b) const
{
	attestElement(a);
	attestElement(b);
	if (a > b)
	{
		throw std::logic_error("First arg must be smaller than second arg!");
	}
	int printCount = 0;
	for (long long i = a; i < b; i++)
	{
		if (has(i))
		{
			printCount++;
			std::cout << i << " ";
		}
	}

	if (printCount == 0)
	{
		std::cout << "No elements found...";
	}

	std::cout << std::endl;
}