#pragma once
#include <exception>
struct OutOfRangeException : public std::exception {
	const char* what() const throw () {
		return "Index is out of range.";
	}
};

