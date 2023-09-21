#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T>
void	print_element(T const &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	iter(T *array, std::size_t len, void (*f)(T const &))
{
	for (std::size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif
