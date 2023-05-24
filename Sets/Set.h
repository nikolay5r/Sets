#pragma once

class Set
{
public:
	Set() = default;

	virtual bool has(long element) const = 0;
	virtual Set* clone() const = 0;
	long next() const;
	long prev() const;

	virtual ~Set() = default;

protected:
	mutable long currentElement = 0;
	void attestElement(long element);
};

