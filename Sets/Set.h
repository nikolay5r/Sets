#pragma once
#include "MyVector.hpp"

class Set
{
public:
	Set() = default;

	virtual bool has(long element) const = 0;
	virtual const Set* clone() const = 0;

	virtual ~Set() = default;

protected:
	void attestElement(long element);
};

