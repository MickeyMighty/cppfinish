#include "Array.hpp"

int	main()
{
	try {
		Array<int>	arr;

		std::cout << "Size is " << arr.size() << std::endl;

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------\n" << std::endl;

	try {
		Array<int>	arr(5);

		for ( unsigned int i = 0; i < arr.size(); i++) {
			arr[i] = i;
			std::cout << "idx " << i << ": " << arr[i] << std::endl;
		}
		std::cout << "Size is " << arr.size() << std::endl;

		arr[-1] = 1;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------\n" << std::endl;

	try {
		Array<int>	arr1(5);
		Array<int>	arr2(6);

		for ( unsigned int i = 0; i < arr1.size(); i++) {
			arr1[i] = i + 1;
			std::cout << "arr1's idx " << i << ": " << arr1[i] << std::endl;
		}

		std::cout << "Size is " << arr2.size() << std::endl;
		arr2 = arr1;

		for ( unsigned int i = 0; i < arr2.size(); i++) {
			std::cout << "arr2's idx " << i << ": " << arr2[i] << std::endl;
		}
		std::cout << "Size is " << arr2.size() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------\n" << std::endl;

	try {
		Array<int>	arr1(5);

		for ( unsigned int i = 0; i < arr1.size(); i++) {
			arr1[i] = i + 10;
			std::cout << "arr1's idx " << i << ": " << arr1[i] << std::endl;
		}

		Array<int>	arr2(arr1);

		for ( unsigned int i = 0; i < arr2.size(); i++) {
			std::cout << "arr2's idx " << i << ": " << arr2[i] << std::endl;
		}
		std::cout << "Size is " << arr2.size() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------\n" << std::endl;

	try {
		Array<std::string>	arr1(5);

		arr1[4] = "Hola!";

		for ( unsigned int i = 0; i < arr1.size(); i++) {
			std::cout << "arr1's idx " << i << ": " << arr1[i] << std::endl;
		}

		Array<std::string>	arr2(6);

		arr2 = arr1;
		for ( unsigned int i = 0; i < arr2.size(); i++) {
			std::cout << "arr2's idx " << i << ": " << arr2[i] << std::endl;
		}

		arr2[2] = "Error";
		for ( unsigned int i = 0; i < arr1.size(); i++) {
			std::cout << "arr1's idx " << i << ": " << arr1[i] << std::endl;
		}
		for ( unsigned int i = 0; i < arr2.size(); i++) {
			std::cout << "arr2's idx " << i << ": " << arr2[i] << std::endl;
		}

		arr2[5];
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----------------------------------\n" << std::endl;
	//system("leaks array");
}
// #include <iostream>
// #include <Array.hpp>
//
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
