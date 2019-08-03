#pragma once
#include <exception>
class ItemNotFoundException :
	public std::exception
{
	const char* what() const throw () {
		return "Item is not in list.";
	}
};

