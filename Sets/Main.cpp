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

void optionsChoice(const Set* set)
{
	std::cout << "\nEnter '1' if you want to print numbers in an interval [a,b];\n"
		<< "Enter '2' if you want to print the next number in row starting from 0;\n"
		<< "Enter '3' if you want to print the previous number in row starting from 0:\n"
		<< "Enter '4' if you want to exit:\n"
		<< "Option: ";

	int option = 0;
	std::cin >> option;

	switch (option)
	{
	case 1:
	{
		long long a, b;
		std::cout << "a: ";
		std::cin >> a;
		std::cout << "b: ";
		std::cin >> b;
		set->print(a, b);
		break;
	}
	case 2:
	{
		long long nextElement = set->next();
		std::cout << "Next element: " << nextElement << std::endl;
		break;
	}
	case 3:
	{
		long long prevElement = set->prev();
		std::cout << "Previous element: " << prevElement << std::endl;
		break;
	}
	case 4:
	{
		return;
		break;
	}
	default:
	{
		throw Invalid_Option("Invalid option read from keyboard!");
		break;
	}
	}

	optionsChoice(set);
}

void runSystem()
{
	const Set* set = nullptr;
	try
	{
		std::cout << "Enter a file name to read a set: ";
		MyString str;
		std::cin >> str;
		set = readSetFromBinary(str.c_str());

		optionsChoice(set);
	}
	catch (const File_Error& error)
	{
		std::cerr << "FILE ERROR: " << error.what() << std::endl;
		runSystem();
	}
	catch (const Invalid_Option& error)
	{
		std::cerr << "INVALID OPTION: " << error.what() << std::endl;
		optionsChoice(set);
	}
	catch (const std::invalid_argument&)
	{

	}
	catch (const std::exception&)
	{

	}
	catch (...)
	{
		std::cerr << "ERROR: Something went wrong! Sorry!";
	}
}

int main()
{
	runSystem();
}
