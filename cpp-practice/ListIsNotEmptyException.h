#pragma once
#include <exception>
struct ListIsEmptyException : 
	public std::exception 
{
	const char* what() const throw () {
		return "List is empty.";
	}
};

