#pragma once
#include "MyString.h";

class File_Error
{
	MyString message;
public:
	File_Error(char* message);
	File_Error(const MyString& message);

	const char* what() const;
	virtual ~File_Error() = default;
};

