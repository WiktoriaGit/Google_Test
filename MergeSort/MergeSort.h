#pragma once


class MergeSort
{
private:
	int* arr;

	int size;

	void mergeSort(int* arr, int left, int right);

	void merge(int* arr, int left, int mid, int right);

public:
	MergeSort();

	MergeSort(int input[], int size);

	~MergeSort();

	void printArray();

	void setArray(int input[], int inputSize);

	void sort();
};

