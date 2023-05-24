#pragma once
#include "Set.h"

class CollectionSet : public Set
{
private:
	void free();
	void copyFrom(const CollectionSet& other);
	void moveFrom(CollectionSet&& other);
protected:
	Set** sets = nullptr;
	size_t size = 0;
	size_t capacity = 0;

public:
	CollectionSet(const Set** sets);
	CollectionSet(const CollectionSet& other);
	CollectionSet(CollectionSet&& other) noexcept;

	void addSet(const Set& set);
	void addSet(Set&& set);
	void removeSet(size_t index);

	CollectionSet& operator=(const CollectionSet& other);
	CollectionSet& operator=(CollectionSet&& other) noexcept;

	virtual ~CollectionSet();
};

