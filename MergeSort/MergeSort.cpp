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

}

MergeSort::~MergeSort()
{
}

