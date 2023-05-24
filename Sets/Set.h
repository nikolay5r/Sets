#pragma once
#include "MyVector.hpp"

class Set
{
public:
	Set() = default;

	bool has(long element) const;
	virtual bool canContain() = 0;
	virtual void add(long element) = 0;
	virtual void remove(long element) = 0;
	size_t size() const;
	bool isEmpty() const;

	virtual ~Set() = default;

protected:
	MyVector<long> elements;

	bool isElementValid(long element) const;
};

