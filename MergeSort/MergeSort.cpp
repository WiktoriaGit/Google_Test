#include <iostream>
#include "MergeSort.h"

/**
* Ustawia MergeSort::size na ```0``` oraz tworzy pust� tablic�
*/
MergeSort::MergeSort()
{
    this->size = 0;
    this->arr = new int[this->size];
}

/**
* Ustawia MergeSort::size na warto�� przekazan� przez parametr ```size``` oraz
* alokuje pami�� dla tablicy MergeSort::arr o rozmiarze ```size```
*
* Inicjalizuje tablic� funkcj� MergeSort::setArray()
*
* Sortuje tablic� wywo�uj�c funkcj� MergeSort::sort()
*/
MergeSort::MergeSort(int input[], int size)
{
    this->size = size;
    this->arr = new int[size];

    this->setArray(input, this->size);

    this->sort();
}

/**
* Destruktor wywo�uje ```delete``` na tablicy, zwalniaj�c pami��.
*/
MergeSort::~MergeSort()
{
    delete[] arr;
}

/**
* Printowanie na ekran poszczeg�lnych element�w tablicy za pomoc� p�tli ```for``` oraz ```std::cout```
*/
void MergeSort::printArray()
{
    for (int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
* Funkcja inicjalizuje tablic�, wype�niaj�c j� indeksami p�tli ```for```
*/
void MergeSort::setArray(int input[], int inputSize)
{
    for (int i = 0; i < inputSize; i++) {
        this->arr[i] = input[i];
    }
}

/**
* Inicjalizuje proces sortowania tablicy wywo�uj�c rekurencyjnie MergeSort::mergeSort.
*
* Funkcja zako�czy si� gdy ```size``` b�dzie ```<= 1```
*/
void MergeSort::sort()
{
    if (size <= 1) 
        return;

    mergeSort(arr, 0, size - 1);
}

/**
* Zwr�cenie wska�nika ```*arr```
*/
int* MergeSort::getArray()
{
    return this->arr;
}

/**
* Wywo�ywana rekurencj�. Wyznacza �rodek tablicy i przekazuje jako parametr granice do podzia�u na mniejsze tablice.
*
* Gdy tablice b�d� wystarczaj�co ma�e, nast�puje wywo�anie MergeSort::merge() aby posortowa� i scali� tablice.
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
* Wyznaczane s� wielko�ci ```n1``` oraz ```n2``` dla nowych tablic ```leftArr``` oraz ```rightArr``` oraz alokacja pami�ci.
*
* Dane s� kopiowane do nowych tablic ```leftArr``` oraz ```rightArr```.
*
* Nast�pnie s� tablice sortowane przez por�wnanie oraz scalane.
*
* Je�eli pozosta�y jakiekolwiek elementy w tablicach, s� one tak�e kopiowane.
*
* Na samym ko�cu nast�puje zwolnienie pami�ci dla dw�ch tymczasowych tablic.
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
