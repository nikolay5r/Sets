#pragma once
#include "Set.h"
class CriteriaSet : public Set
{
private:
	bool (*pred)(long element) = nullptr;
	MyVector<long> criteriaElements;

	void attestCriteriaElement(long element);
	void attestElementWithCriteriaFunc(long element);

public:
	CriteriaSet(MyVector<long> criteriaElements, bool (*pred)(long element));
	CriteriaSet(size_t numberOfCriteriaElements, long* criteriaElements, bool (*pred)(long element));

	void add(long element) override;
	void remove(long element) override;
	bool canContain(long element) override;

	~CriteriaSet() = default;
};

