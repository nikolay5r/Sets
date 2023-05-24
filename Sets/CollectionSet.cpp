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
	capacity = other.capacity;
	sets = new Set * [capacity];

	for (size_t i = 0; i < size; i++)
	{
		sets[i] = other.sets[i]->clone();
	}
}

void CollectionSet::moveFrom(CollectionSet&& other) noexcept
{
	size = other.size;
	capacity = other.capacity;
	sets = other.sets;
	other.sets = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void CollectionSet::resize(size_t capacity)
{
	this->capacity = capacity;
	Set** newSets = new Set * [capacity];

	for (size_t i = 0; i < size; i++)
	{
		newSets[i] = sets[i];
		sets[i] = nullptr;
	}

	delete[] sets;
	sets = newSets;
}

CollectionSet::CollectionSet(size_t capacity) : capacity(capacity)
{
	sets = new Set * [capacity];
}

CollectionSet::CollectionSet(const Set** sets, size_t numberOfSets) : capacity(numberOfSets), size(numberOfSets)
{
	this->sets = new Set * [capacity];

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

void CollectionSet::removeSet(size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index passed when removeSet function was called!");
	}

	delete sets[index];
	sets[index] = sets[size - 1];
	sets[size--] = nullptr;
}

void CollectionSet::addSet(const Set& set)
{
	if (size == capacity)
	{
		resize(capacity * RESIZE_COEF);
	}

	sets[size++] = set.clone();
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