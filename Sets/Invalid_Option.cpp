#include "Invalid_Option.h"
#include "MyString.h"

Invalid_Option::Invalid_Option(char* message) : message(message) {}

Invalid_Option::Invalid_Option(const MyString& message) : message(message) {}

const char* Invalid_Option::what() const
{
	return message.c_str();
}
