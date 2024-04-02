#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno> // For errno
#include <climits> // For INT_MIN and INT_MAX
#include <iomanip>
class ScalarConverter{
	private:
		ScalarConverter(){}
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
	public:
		static void convert(const std::string& literal);
};
#endif