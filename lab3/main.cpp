#include "Array3d.h"
#include <iostream>

int main()
{ 
	setlocale(LC_ALL, "Rus");
	Array3d<int> arr = Array3d<int>(3,3,3);
	arr(0,0,0) = 1;
	arr(1, 1, 1) = 111;
	arr.zeros();
	std::cout << arr(0, 0, 0) << "\t" << arr(1, 1, 1) << std::endl;
	arr.ones();
	std::cout << arr(0, 0, 0) << "\t" << arr(1, 1, 1) << std::endl;
	arr.fill(13);
	std::cout << arr(0, 0, 0) << "\t" << arr(1, 1, 1) << std::endl;

	std::vector<std::vector<int>> subArray = { {1,2,3}, {4,5,6}, {7,8,9} };
	arr.setValues0(0, subArray);

	subArray = arr.getValues0(0);
	for (auto str : subArray)
	{
		for (auto value : str)
			std::cout << value << " ";
		std::cout << std::endl;
	}

	return 0;
}