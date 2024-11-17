/**
 * @file test.cpp
 */

#include "pch.h"

#include "../MergeSort/MergeSort.h"
#include "../MergeSort/MergeSort.cpp"

#include <algorithm>
#include <cstdlib>


/**
* @brief Test który sprawdza, czy funkcja zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy test poprawnie zrobi fail, gdy ręcznie ustawimy inną wartość.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Ręcznia zmiana wartości indeksu 0: ```tempArray[0] = 999;```
* 
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę podaną w odwrotnej kolejności.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
* 
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę ujemnych wartości.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę ujemnych i dodatnich wartości.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę dodatnich wartości z duplikatami.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę ujemnych wartości z duplikatami.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę dodatnich losowych wartości.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* Aby wygenerować losowe wartości, użyto funkcji ```rand()```
* 
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
TEST(Sortowanie, SortowanieLosowejTablicyLiczb)
{
	int size = 10;
	int input[10];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		input[i] = rand() % 20;
	}

	MergeSort arrayToSort(input, size);
	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 1; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

/**
* @brief Test który sprawdza, czy stworzenie pustej tablicy nie rzuci wyjątku.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* Do sprawdzenia rzucenia wyjątku, użyto makra ```ASSERT_NO_THROW```
* 
* @param Sortowanie
* @param TablicaNiezmieniona
*/
TEST(Inicjalizacja, NieRzucaWyjatkiem)
{
	int input[] = { 0 };
	int size = sizeof(input) / sizeof(input[0]);


	ASSERT_NO_THROW(MergeSort arrayToSort(input, size));
}

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę wartości dodatnich, ujemnych z duplikatami.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę dwuelementową rosnącą.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje dużą tablicę dodatnich losowych wartości.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* Aby wygenerować losowe wartości, użyto funkcji ```rand()```
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje dużą tablicę losowych wartości dodatnich, ujemnych i duplikatów.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* Aby wygenerować losowe wartości, użyto funkcji ```rand()```
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
TEST(Sortowanie, SortowanieDuzejTablicyPonad100ElementowUjemnychDodatnichDuplikatow)
{
	int size = 150;
	int input[150];

	srand((unsigned)time(NULL));

	for (int i = 0; i < size; i++)
	{
		input[i] = (rand() % 201) - 100;
	}

	MergeSort arrayToSort(input, size);

	int* tempArray = arrayToSort.getArray();

	std::sort(std::begin(input), std::end(input));

	for (int i = 0; i < size; i++)
	{
		EXPECT_EQ(input[i], tempArray[i]) << "Wartosc " << input[i] << " nie rowna sie wartosci " << tempArray[i];
	}
}

/**
* @brief Test który sprawdza, czy funkcja poprawnie przesortuje tablicę jednoelementową.
*
* Tablica ```input``` zawiera już posortowane wartości. Są to dane wejściowe.
*
* Zmienna ```size``` przechowuje wielkość tablicy.
*
* MergeSort tworzy obiekt z tablicą ```input``` oraz obiektem ```size```.
*
* Poprzez wywołanie MergeSort MergeSort::getArray(), wskaźnik do MergeSort::arr jest przekazany do zmiennej ```tempArray```.
*
* Wywołanie ```std::sort``` na tablicy, aby przesortować podaną tablicę z biblioteki ```cstdlib```
*
* Pętla ```for``` porównuje makrem ```EXPECT_EQ``` wartości tablicy ```inputArray``` z tablicą ```tempArray```.
*
* @param Sortowanie
* @param TablicaNiezmieniona
*/
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

