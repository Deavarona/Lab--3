#include <iostream>
#include <conio.h>
#include <string>

template <typename T>
T max(T first, T second)
{
	std::cout << "Template function" << std::endl;
	return (first >= second) ? first : second;
}

std::string max(std::string first, std::string second)
{
	std::cout << "Specialized function" << std::endl;
	return (first >= second) ? first : second;
}

template <typename T>
T input(T&expression)
{
	std::cout << "Template function" << std::endl;
	while (1)
	{
		std::cout << "Input expression: ";
		std::cin >> expression;
		if (std::cin.get() == '\n')
			return expression;
		else
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Incorrect input!" << std::endl;
		}
	}
}

void integer();
void real();
void string();

int main()
{
	std::cout << "1. Compare integer numbers" << std::endl;
	std::cout << "2. Compare real numbers" << std::endl;
	std::cout << "3. Compare strings" << std::endl;

	switch (_getch())
	{
	case '1': integer(); break;
	case '2': real(); break;
	case '3': string(); break;
	}
}

void integer()
{
	int first_int_number, second_int_number; 
	input(first_int_number); 
	input(second_int_number); 
	std::cout <<"Max (" << first_int_number << ";" << second_int_number << ") = " << max(first_int_number, second_int_number);
}

void real()
{
	double first_real_number, second_real_number; 
	input(first_real_number); 
	input(second_real_number); 
	std::cout << "Max ("<< first_real_number << ";" << second_real_number << ") = " << max(first_real_number, second_real_number);
}

void string()
{
	std::string first_string, second_string; 
	std::cout << "First string: ";
	std::getline(std::cin, first_string); 
	std::cout << "Second string: ";
	std::getline(std::cin, second_string); 
	std::cout << "Max (" << first_string << ";" << second_string << ") = " << max(first_string, second_string);
}