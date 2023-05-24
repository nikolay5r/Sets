#include "CollectionSet.h"
#include <utility>
#include <stdexcept>

static const int INITIAL_CAPACITY = 4;
static const int RESIZE_COEF = 2;

void CollectionSet::free()
{
	if (sets)
	{
		for (size_t i = 0; i < size; i++)
		{
			delete sets[i];
			sets[i] = nullptr;
		}

		delete[] sets;
	}
}

void CollectionSet::copyFrom(const CollectionSet& other)
{
	size = other.size;
	sets = new Set * [size];

	for (size_t i = 0; i < size; i++)
	{
		sets[i] = other.sets[i]->clone();
	}
}

void CollectionSet::moveFrom(CollectionSet&& other) noexcept
{
	size = other.size;
	sets = other.sets;
	other.sets = nullptr;
	other.size = 0;
}

CollectionSet::CollectionSet(const Set** sets, size_t numberOfSets) : size(numberOfSets)
{
	this->sets = new Set * [size];

	for (size_t i = 0; i < numberOfSets; i++)
	{
		this->sets[i] = sets[i]->clone();
	}
}

CollectionSet::CollectionSet(const CollectionSet& other)
{
	copyFrom(other);
}

CollectionSet::CollectionSet(CollectionSet&& other) noexcept
{
	moveFrom(std::move(other));
}

CollectionSet& CollectionSet::operator=(const CollectionSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

CollectionSet& CollectionSet::operator=(CollectionSet&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CollectionSet::~CollectionSet()
{
	free();
}