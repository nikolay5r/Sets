#include "Set.h"
#include "MyVector.hpp"
#include <limits>

static const long long ERROR_NUMBER = 100000000;

void Set::attestElement(long long element) const
{
	if (element < INT_MIN || element > UINT_MAX)
	{
		throw std::out_of_range("Invalid Element!\n Element is out of range for the set!\n Elements in set should be between 2^32-1 and -2^16+1");
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
		if (currentElement + ERROR_NUMBER == i)
		{
			throw std::runtime_error("The next number in line cannot be found!");
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
		if (currentElement - ERROR_NUMBER == i)
		{
			throw std::runtime_error("The previous number in line cannot be found!");
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