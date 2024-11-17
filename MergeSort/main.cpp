#include <iostream>

#include "MergeSort.h"

int main()
{

	int input[] = { 38, 27, 43, 3, 9, 82, 10 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	std::cout << "Poczatkowa tablica: ";

	for (int i = 0; i < size; i++)
	    std::cout << input[i] << " ";
	
	std::cout << std::endl;

	std::cout << "Posortowana tablica: ";
	arrayToSort.printArray();


	return 0;
}