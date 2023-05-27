#pragma once
#include <limits>

class Set
{
public:
	Set() = default;

	virtual bool has(long long element) const = 0;
	virtual Set* clone() const = 0;
	long long next() const;
	void print(long long a, long long b) const;

	virtual ~Set() = default;

protected:
	mutable long long currentElement = INT_MIN;
	void attestElement(long long element) const;
};

