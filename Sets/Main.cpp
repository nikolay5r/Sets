#include <iostream>
#include <fstream>
#include "Set.h"
#include "CriteriaSet.h"
#include "IntersectionSet.h"
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

void readElementsFromBinary(std::ifstream& file, MyVector<long long>& elements)
{
	if (!file.is_open())
	{
		throw File_Error("File with that name doesn't exist!");
	}

	size_t numberOfElements = elements.size();

	for (size_t i = 0; i < numberOfElements; i++)
	{
		file.read((char*)&elements[i], sizeof(int));
	}
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

	return buff;
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

	switch (t)
	{
	case 0:
	{
		MyVector<long long> elements(n, 0);
		readElementsFromBinary(file, elements);
		set = new CriteriaSet(criteriaFunctions::isEqualTo, elements);
		break;
	}

	case 1:
	{
		MyVector<long long> elements(n, 0);
		readElementsFromBinary(file, elements);
		set = new CriteriaSet(criteriaFunctions::isNotDivisibleTo, elements);
		break;
	}

	case 2:
	{
		MyVector<long long> elements(n, 0);
		readElementsFromBinary(file, elements);
		set = new CriteriaSet(criteriaFunctions::isDivisibleTo, elements);
		break;
	}

	case 3:
	{
		const Set** sets = readSetsFromBinary(file, n);
		set = new UnionSet(sets, n);
		delete[] sets;
		break;
	}

	case 4:
	{
		const Set** sets = readSetsFromBinary(file, n);
		set = new IntersectionSet(sets, n);
		delete[] sets;
		break;
	}

	default:
	{
		set = nullptr;
		throw File_Error("Invalid option read from file!");
		break;
	}
	}

	file.close();
	return set;
}

void fileSystem(const Set*& set)
{
	std::cout << "Enter a file name to read a set: ";
	MyString str;
	std::cin >> str;
	set = readSetFromBinary(str.c_str());
}

void optionsSystem(const Set* set)
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

	optionsSystem(set);
}

void runSystem()
{
	static const Set* set = nullptr;
	try
	{
		if (!set)
		{
			fileSystem(set);
		}

		optionsSystem(set);
	}
	catch (const File_Error& error)
	{
		std::cerr << "FILE_ERROR: " << error.what() << std::endl;
		if (set)
		{
			delete set;
			set = nullptr;
		}
		runSystem();
	}
	catch (const Invalid_Option& error)
	{
		std::cerr << "INVALID_OPTION: " << error.what() << std::endl;
		runSystem();
	}
	catch (const std::out_of_range& error)
	{
		std::cerr << "OUT_OF_RANGE: " << error.what() << std::endl;
		runSystem();
	}
	catch (const std::logic_error& error)
	{
		std::cerr << "LOGIC_ERROR: " << error.what() << std::endl;
		runSystem();
	}
	catch (const std::runtime_error& error)
	{
		std::cerr << "RUNTIME_ERROR: " << error.what() << std::endl;
		runSystem();
	}
	catch (const std::invalid_argument& error)
	{
		std::cerr << "INVALID_ARGUMENT: " << error.what() << std::endl;
		if (set)
		{
			delete set;
			set = nullptr;
		}
		runSystem();
	}
	catch (const std::exception& error)
	{
		std::cerr << "ERROR: " << error.what() << " No Handling for this exception right now!" << std::endl;
		if (set)
		{
			delete set;
			set = nullptr;
		}
		runSystem();
	}
	catch (...)
	{
		std::cerr << "ERROR: Something went wrong! Sorry!";
	}

	if (set)
	{
		delete set;
		set = nullptr;
	}
}

int main()
{
	runSystem();
}
