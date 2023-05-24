#include "File_Error.h"
#include "MyString.h"

File_Error::File_Error(char* message) : message(message) {}

File_Error::File_Error(const MyString& message) : message(message) {}

const char* File_Error::what() const
{
	return message.c_str();
}
