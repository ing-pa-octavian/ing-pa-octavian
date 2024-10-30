﻿#include<iostream>
using namespace std;
void merge(int array[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = array[mid + 1 + i];
	int i = 0; j = 0; k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			array[k] = L[i];
			i++;
		}
		else {
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		array[k] = R[j];
		j++;
		k++
	}
}
void mergeSort(int array[], int left, int right) {
	if (left < right) {
		int mid = left+(right - left) / 2;
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
}
}
void printArray(int A[], int size) {
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}
int main()
{
	int array[] = { 12,11,13,5,6,7 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << "Araiul la inceput: ";
	printArray(array, size);
	mergeSort(array, 0, size - 1);
	cout << "Araiul sortat: ";
	printArray(array, size);
	return 0;
}