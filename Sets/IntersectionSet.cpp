#include "IntersectionSet.h"

IntersectionSet::IntersectionSet(const Set** sets, size_t numberOfSets) : CollectionSet(sets, numberOfSets) {}

bool IntersectionSet::has(long element) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!sets[i]->has(element))
		{
			return false;
		}
	}

	return true;
}

Set* IntersectionSet::clone() const
{
	return new IntersectionSet(*this);
}