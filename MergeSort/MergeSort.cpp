#include <iostream>
#include "MergeSort.h"

/**
* Ustawia MergeSort::size na ```0``` oraz tworzy pustą tablicę
*/
MergeSort::MergeSort()
{
    this->size = 0;
    this->arr = new int[this->size];
}

/**
* Ustawia MergeSort::size na wartość przekazaną przez parametr ```size``` oraz
* alokuje pamięć dla tablicy MergeSort::arr o rozmiarze ```size```
*
* Inicjalizuje tablicę funkcją MergeSort::setArray()
*
* Sortuje tablicę wywołując funkcję MergeSort::sort()
*/
MergeSort::MergeSort(int input[], int size)
{
    this->size = size;
    this->arr = new int[size];

    this->setArray(input, this->size);

    this->sort();
}

/**
* Destruktor wywołuje ```delete``` na tablicy, zwalniając pamięć.
*/
MergeSort::~MergeSort()
{
    delete[] arr;
}

/**
* Printowanie na ekran poszczególnych elementów tablicy za pomocą pętli ```for``` oraz ```std::cout```
*/
void MergeSort::printArray()
{
    for (int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
* Funkcja inicjalizuje tablicę, wypełniając ją indeksami pętli ```for```
*/
void MergeSort::setArray(int input[], int inputSize)
{
    for (int i = 0; i < inputSize; i++) {
        this->arr[i] = input[i];
    }
}

/**
* Inicjalizuje proces sortowania tablicy wywołując rekurencyjnie MergeSort::mergeSort.
*
* Funkcja zakończy się gdy ```size``` będzie ```<= 1```
*/
void MergeSort::sort()
{
    if (size <= 1) 
        return;

    mergeSort(arr, 0, size - 1);
}

/**
* Zwrócenie wskaźnika ```*arr```
*/
int* MergeSort::getArray()
{
    return this->arr;
}

/**
* Wywoływana rekurencją. Wyznacza środek tablicy i przekazuje jako parametr granice do podziału na mniejsze tablice.
*
* Gdy tablice będą wystarczająco małe, następuje wywołanie MergeSort::merge() aby posortować i scalić tablice.
*/
void MergeSort::mergeSort(int* arr, int left, int right)
{
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/**
* Wyznaczane są wielkości ```n1``` oraz ```n2``` dla nowych tablic ```leftArr``` oraz ```rightArr``` oraz alokacja pamięci.
*
* Dane są kopiowane do nowych tablic ```leftArr``` oraz ```rightArr```.
*
* Następnie są tablice sortowane przez porównanie oraz scalane.
*
* Jeżeli pozostały jakiekolwiek elementy w tablicach, są one także kopiowane.
*
* Na samym końcu następuje zwolnienie pamięci dla dwóch tymczasowych tablic.
*/
void MergeSort::merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];


    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

int* MergeSort::getArray()
{
    return this->arr;
}
