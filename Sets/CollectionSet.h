#pragma once
#include "Set.h"

class CollectionSet : public Set
{
private:
	void free();
	void copyFrom(const CollectionSet& other);
	void moveFrom(CollectionSet&& other) noexcept;
	void resize(size_t capacity);

protected:
	Set** sets = nullptr;
	size_t size = 0;

public:
	CollectionSet(const Set** sets, size_t numberOfSets);
	CollectionSet(const CollectionSet& other);
	CollectionSet(CollectionSet&& other) noexcept;

	CollectionSet& operator=(const CollectionSet& other);
	CollectionSet& operator=(CollectionSet&& other) noexcept;

	virtual ~CollectionSet();
};

