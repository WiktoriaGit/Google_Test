/**
 * @file MergeSort.h
 */

#pragma once

 /**
  * \brief Klasa MergeSort
  *
  * Klasa ta reprezentuje algorytm sortowania przez scalanie.
  * Zawiera metody będące implementacją algorytmu sortującego.
  *
  */
class MergeSort
{
private:
	int* arr;	/**< Wskaźnik na dynamicznie alokowaną tablicę */

	int size;	/**< Przechowuje wielkość tablicy */

	/**
	* @brief Funkcja dzieląca tablice na mniejsze tablice
	* @param *arr tablica która będzie dalej dzielona na mniejsze części
	* @param left Lewy indeks tablicy
	* @param right Prawy indeks tablicy
	*/
	void mergeSort(int* arr, int left, int right);

	/**
	* @brief Funkcja sortująca i scalająca tablice
	* @param *arr tablica która będzie scalana
	* @param left Lewy indeks tablicy
	* @param mid Środkowy indeks tablicy
	* @param right Prawy indeks tablicy
	*/
	void merge(int* arr, int left, int mid, int right);

public:

	/**
	* @brief Konstruktor domyślny klasy MergeSort
	*/
	MergeSort();

	/**
	* @brief Konstruktor używany do tworzenia obiektu tablicy o danym rozmiarze.
	* @param input[] Tablica przekazana do konstruktora, która będzie posortowana.
	* @param size wielkość przekazanej tablicy
	*/
	MergeSort(int input[], int size);

	/**
	* @brief Domyślny destruktor
	*/
	~MergeSort();

	/**
	* @brief Funkcja printująca całą tablicę na konsolę.
	*/
	void printArray();

	/**
	* @brief Funkcja inicjalizująca tablicę.
	* @param input[] tablica która będzie inicjalizowana.
	* @param inputSize rozmiar tablicy do inicjalizacji.
	*/
	void setArray(int input[], int inputSize);

	/**
	* @brief Funkcja inicjująca proces sortowania
	*/
	void sort();

	/**
	* @brief Getter - Funkcja zwraca wskaźnik MergeSort::arr
	*/
	int* getArray();
};

