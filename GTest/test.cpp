#include "pch.h"

#include "../MergeSort/MergeSort.h"
#include "../MergeSort/MergeSort.cpp"

TEST(Sortowanie, TablicaNiezmieniona)
{
	int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}