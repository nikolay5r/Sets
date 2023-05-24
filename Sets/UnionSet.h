#pragma once
#include "Set.h"
#include "CollectionSet.h"

class UnionSet : public CollectionSet
{
public:
	UnionSet(const Set** sets, size_t numberOfSets);

	bool has(long element) const override;
	Set* clone() const override;
};

