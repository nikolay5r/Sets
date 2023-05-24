#pragma once

class Set
{
public:
	Set() = default;

	virtual bool has(long long element) const = 0;
	virtual Set* clone() const = 0;
	long long next() const;
	long long prev() const;
	void print(long long a, long long b) const;

	virtual ~Set() = default;

protected:
	mutable long long currentElement = 0;
	void attestElement(long long element) const;
};

