#include "UnionSet.h"
#include "Set.h"
#include "CollectionSet.h"

UnionSet::UnionSet(const Set** sets, size_t numberOfSets) : CollectionSet(sets, numberOfSets) {}

bool UnionSet::has(long element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (sets[i]->has(element))
		{
			return true;
		}
	}

	return false;
}

Set* UnionSet::clone() const
{
	return new UnionSet(*this);
}

