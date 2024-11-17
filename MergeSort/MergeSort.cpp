#include <iostream>
#include "MergeSort.h"


MergeSort::MergeSort()
{
    this->size = 0;
    this->arr = new int[this->size];
}

MergeSort::MergeSort(int input[], int size)
{
    this->size = size;
    this->arr = new int[size];

    this->setArray(input, this->size);

    this->sort();
}

MergeSort::~MergeSort()
{
    delete[] arr;
}

void MergeSort::printArray()
{
    for (int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

void MergeSort::setArray(int input[], int inputSize)
{
    for (int i = 0; i < inputSize; i++) {
        this->arr[i] = input[i];
    }
}

void MergeSort::sort()
{
    if (size <= 1) 
        return;

    mergeSort(arr, 0, size - 1);
}

void MergeSort::mergeSort(int* arr, int left, int right)
{
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

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
