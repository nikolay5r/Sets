#include <iostream>
#include <fstream>
#include "Set.h"
#include "CriteriaSet.h"
#include "IntersectionSet.h"
#include "SetCriteriaFunctions.h"
#include "UnionSet.h"
#include "MyString.h"
#include "File_Error.h"
#include "Invalid_Option.h"

const Set** readSetsFromBinary(std::ifstream& file, size_t numberOfSets);
const Set* readSetFromBinary(const char* fileName);
const char* readFileNameFromBinary(std::ifstream& file);

const Set** readSetsFromBinary(std::ifstream& file, size_t numberOfSets)
{
	if (!file.is_open())
	{
		throw File_Error("File with that name doesn't exist!");
	}

	const Set** sets = new const Set * [numberOfSets] {nullptr};
	for (size_t i = 0; i < numberOfSets; i++)
	{
		const char* buff = readFileNameFromBinary(file);
		sets[i] = readSetFromBinary(buff);
		delete[] buff;
	}

	return sets;
}

const long long* readElementsFromBinary(std::ifstream& file, size_t numberOfElements)
{
	if (!file.is_open())
	{
		throw File_Error("File with that name doesn't exist!");
	}

	long long* elements = new long long[numberOfElements];
	for (size_t i = 0; i < numberOfElements; i++)
	{
		file.read((char*)&elements[i], sizeof(int));
	}

	return elements;
}

const char* readFileNameFromBinary(std::ifstream& file)
{
	if (!file.is_open())
	{
		throw File_Error("File with that name doesn't exist!");
	}

	size_t length = 0;
	file.read((char*)&length, sizeof(length));
	char* buff = new char[length + 1];
	file.read(buff, length + 1);
	delete[] buff;
}

const Set* readSetFromBinary(const char* fileName)
{
	std::ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		throw File_Error("File with that name doesn't exist!");
	}

	unsigned short n = 0, t = 0;

	file.read((char*)&n, sizeof(n));
	file.read((char*)&t, sizeof(t));

	Set* set = nullptr;
	const Set** sets = nullptr;
	const long long* elements = nullptr;

	switch (t)
	{
	case 0:
		elements = readElementsFromBinary(file, n);
		set = new CriteriaSet(n, elements, criteria::isEqualTo);
		delete[] elements;
		break;

	case 1:
		elements = readElementsFromBinary(file, n);
		set = new CriteriaSet(n, elements, criteria::isNotDivisibleTo);
		delete[] elements;
		break;

	case 2:
		elements = readElementsFromBinary(file, n);
		set = new CriteriaSet(n, elements, criteria::isDivisibleTo);
		delete[] elements;
		break;

	case 3:
		sets = readSetsFromBinary(file, n);
		set = new UnionSet(sets, n);
		delete[] sets;
		break;

	case 4:
		sets = readSetsFromBinary(file, n);
		set = new IntersectionSet(sets, n);
		delete[] sets;
		break;

	default:
		set = nullptr;
		throw File_Error("Invalid option read from file!");
		break;
	}
	return set;
}
}

int main()
{
	std::cout << "Hello World!\n";
}
