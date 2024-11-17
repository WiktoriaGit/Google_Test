#include <iostream>
#include "MergeSort.h"

/**
* Ustawia MergeSort::size na ```0``` oraz tworzy pust¹ tablicê
*/
MergeSort::MergeSort()
{
    this->size = 0;
    this->arr = new int[this->size];
}

/**
* Ustawia MergeSort::size na wartoœæ przekazan¹ przez parametr ```size``` oraz
* alokuje pamiêæ dla tablicy MergeSort::arr o rozmiarze ```size```
*
* Inicjalizuje tablicê funkcj¹ MergeSort::setArray()
*
* Sortuje tablicê wywo³uj¹c funkcjê MergeSort::sort()
*/
MergeSort::MergeSort(int input[], int size)
{
    this->size = size;
    this->arr = new int[size];

    this->setArray(input, this->size);

    this->sort();
}

/**
* Destruktor wywo³uje ```delete``` na tablicy, zwalniaj¹c pamiêæ.
*/
MergeSort::~MergeSort()
{
    delete[] arr;
}

/**
* Printowanie na ekran poszczególnych elementów tablicy za pomoc¹ pêtli ```for``` oraz ```std::cout```
*/
void MergeSort::printArray()
{
    for (int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
* Funkcja inicjalizuje tablicê, wype³niaj¹c j¹ indeksami pêtli ```for```
*/
void MergeSort::setArray(int input[], int inputSize)
{
    for (int i = 0; i < inputSize; i++) {
        this->arr[i] = input[i];
    }
}

/**
* Inicjalizuje proces sortowania tablicy wywo³uj¹c rekurencyjnie MergeSort::mergeSort.
*
* Funkcja zakoñczy siê gdy ```size``` bêdzie ```<= 1```
*/
void MergeSort::sort()
{
    if (size <= 1) 
        return;

    mergeSort(arr, 0, size - 1);
}

/**
* Zwrócenie wskaŸnika ```*arr```
*/
int* MergeSort::getArray()
{
    return this->arr;
}

/**
* Wywo³ywana rekurencj¹. Wyznacza œrodek tablicy i przekazuje jako parametr granice do podzia³u na mniejsze tablice.
*
* Gdy tablice bêd¹ wystarczaj¹co ma³e, nastêpuje wywo³anie MergeSort::merge() aby posortowaæ i scaliæ tablice.
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
* Wyznaczane s¹ wielkoœci ```n1``` oraz ```n2``` dla nowych tablic ```leftArr``` oraz ```rightArr``` oraz alokacja pamiêci.
*
* Dane s¹ kopiowane do nowych tablic ```leftArr``` oraz ```rightArr```.
*
* Nastêpnie s¹ tablice sortowane przez porównanie oraz scalane.
*
* Je¿eli pozosta³y jakiekolwiek elementy w tablicach, s¹ one tak¿e kopiowane.
*
* Na samym koñcu nastêpuje zwolnienie pamiêci dla dwóch tymczasowych tablic.
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
