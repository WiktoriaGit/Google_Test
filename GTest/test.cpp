#include "pch.h"

#include "../MergeSort/MergeSort.h"
#include "../MergeSort/MergeSort.cpp"

#include <algorithm>
#include <cstdlib>

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

TEST(Sortowanie, TablicaNiezmienionaFail)
{
	int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	tempArray[0] = 999;
	EXPECT_NE(input[0], tempArray[0]) << "Wartosc " << input[0] << " nie rowna sie wartosci " << tempArray[0];

	for (int i = 1; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, SortowanieTablicyOdwrotnejKolejnosci)
{
	int input[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, SortowanieTablicyUjemnychWartosci)
{
	int input[] = { -38, -27, -43, -3, -9, -82, -10 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, SortowanieTablicyUjemnychIDodatnichWartosci)
{
	int input[] = { -38, 27, -43, 3, -9, 82, -10 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}


TEST(Sortowanie, SortowanieTablicyZDuplikatami)
{
	int input[] = { 4, 1, 4, 2, 1, 3, 4 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}


TEST(Sortowanie, SortowanieTablicyZUjemnymiDuplikatami)
{
	int input[] = { -5, -10, -5, -30, -5, -30, -4 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, SortowanieLosowejTablicyLiczb)
{
	int size = 10;
	int input[10];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		input[i] = rand() % 20;
	}

	//std::cout << "tablica wejsciowa: ";

	//for (int i = 0; i < size; i++)
	//{
	//	std::cout << input[i] << " ";
	//}

	//std::cout << std::endl;

	MergeSort arrayToSort(input, size);
	int* tempArray = arrayToSort.getArray();



	std::sort(std::begin(input), std::end(input));

	for (int i = 1; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Inicjalizacja, NieRzucaWyjatkiem)
{
	int input[] = { 0 };
	int size = sizeof(input) / sizeof(input[0]);


	ASSERT_NO_THROW(MergeSort arrayToSort(input, size));
}

TEST(Sortowanie, SortowanieTablicyUjemnychDodatnichIDuplikatow)
{
	int input[] = { -10, 5, -3, 5, 8, -10, 2, -3, 8 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, SortowanieTablicyDwaElementyRosnaco)
{
	int input[] = { 1, 2 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, SortowanieDuzejTablicyPonad100Elementow)
{
	int size = 150;
	int input[150];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		input[i] = rand() % 1000;
	}

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

TEST(Sortowanie, TablicaJednoelementowa)
{
	int input[] = { 42 };
	int size = sizeof(input) / sizeof(input[0]);

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

