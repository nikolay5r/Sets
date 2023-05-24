#pragma once
#include "Set.h"
#include "CollectionSet.h"

class IntersectionSet : public CollectionSet
{
public:
	IntersectionSet(const Set** sets, size_t numberOfSets);

	bool has(long long element) const override;
	Set* clone() const override;
};

