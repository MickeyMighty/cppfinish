#include "iter.hpp"
#include <string>

int	main()
{
	// int array
	int	int_array[5] = {1, 2, 3, 4, 5};
	iter(int_array, 5, print_element);
	std::cout << std::endl;

	// double array
	double	double_array[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
	iter(double_array, 5, print_element);
	std::cout << std::endl;

	float	float_array[5] = {2.1f, 2.2f, 2.3f, 2.4f, 2.5f};
	iter(float_array, 5, print_element);
	std::cout << std::endl;

	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(char_array, 5, print_element);
	std::cout << std::endl;

	std::string	string_array[5] = {"string1", "string2", "string3", "string4", "string5"};
	iter(string_array, 5, print_element);
	return (0);
}
