#include "UnionSet.h"
#include "Set.h"
#include "CollectionSet.h"
#include <limits>

UnionSet::UnionSet(const Set** sets, size_t numberOfSets) : CollectionSet(sets, numberOfSets) {}

bool UnionSet::has(long long element) const
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
