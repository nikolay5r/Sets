#pragma once
#include "MyString.h"
class Invalid_Option
{
	MyString message;

public:
	Invalid_Option(char* message);
	Invalid_Option(const MyString& message);

	const char* what() const;
	virtual ~Invalid_Option() = default;

};

