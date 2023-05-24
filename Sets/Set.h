#pragma once
class Set
{
protected:

	void setBaseElements(size_t numberOfElements, long* elements);

public:

	void getBaseElements() const;
	virtual bool has(long element) = 0;
	virtual void add(long element) = 0;
	bool isSetInfinite() const;

private:
	long* baseElements = nullptr;
	size_t numberOfElements = 0;
	bool isInfinite = true;

};

