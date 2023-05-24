#include <iostream>
#include <fstream>
#include "Set.h"

const Set* readSetFromBinary(char* filePath)
{
	std::ifstream file(filePath, std::ios::binary);

	unsigned short n = 0, t = 0;

	file.read((char*)&n, sizeof(n));
	file.read((char*)&t, sizeof(t));

	long* elements =
}

int main()
{
	std::cout << "Hello World!\n";
}
