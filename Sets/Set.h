#pragma once

class Set
{
public:
	Set() = default;

	virtual bool has(long element) const = 0;
	virtual Set* clone() const = 0;

	virtual ~Set() = default;

protected:
	void attestElement(long element);
};

