#include "ArrayADT.h"

template<class T>
void Array<T>::displayArr() {
	std::cout << "Elements are : \n";
	for (int i = 0; i <length; i++) {
		std::cout << A[i] << " ";
	}
	std::cout << "\n";
}

template<class T>
void Array<T>::Append(T x) {

	if (length < size)
		A[length++] = x;
}

template<class T>
void Array<T>::Insert(int index, T x) {

	int i;
	if (index >= 0 && index <= length) {
		for (i = length; i > index; i--)
			A[i] = A[i - 1];
		A[index] = x;
		length++;
	}
	else {
		std::cout << "Index Invalid.\n";
	}
}

template<class T>
T Array<T>::Delete(int index) {

	int i, temp;
	if (index >= 0 && index <= length) {
		temp = A[index];
		for (i = index; i < length - 1; i++)
			A[i] = A[i + 1];
		length--;
		return temp;
	}
	else {
		std::cout << "Index Invalid.\n";
	}
	return 0;
}

template<class T>
int Array<T>::LinearSearch(int key) {

	int i = 0;
	for (i = 0; i < length; i++) {
		if (A[i] == key)
			return i;
	}
	return -1;
}

template<class T>
int Array<T>::BinarySearch(int key) {
	int low = 0;
	int high = length - 1;
	int mid = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			high = mid - 1;
		else if (key > A[mid])
			low = mid + 1;
	}
	return -1;
}

template<class T>
int Array<T>::get(int index) {
	if (index >= 0 && index < length)
		return A[index];
	else {
		std::cout << "Index Out of Bounds.\n";
		return -1;
	}
}

template<class T>
void Array<T>::set(int index, T x) {
	if (index >= 0 && index < length)
		A[index] = x;
	else {
		std::cout << "Index Out of Bounds.\n";
	}
}

template<class T>
int Array<T>::Max() {
	int i = 0, max = A[0];

	for (i = 1; i < length; i++)
		if (A[i] > max)
			max = A[i];
	return max;
}

template<class T>
int Array<T>::Min() {
	int i = 0, min = A[0];

	for (i = 1; i < length; i++)
		if (A[i] < min)
			min = A[i];
	return min;
}

template<class T>
int Array<T>::Sum() {
	int total = 0, i = 0;
	for (i = 0; i < length; i++)
		total += A[i];

	return total;
}

template<class T>
float Array<T>::Avg() {
	int total = 0;
	total = Sum();
	return total / length;
}

template<class T>
void Array<T>::Reverse() {
	int i = 0, j = 0;
	int temp = 0;
	for (i = 0, j = length - 1; i < j; i++, j--) {
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	displayArr();
}

template<class T>
bool Array<T>::isSorted() {
	int i = 0;

	for (i = 0; i < length - 1; i++)
		if (A[i] > A[i + 1])
			return false;
	return true;
}
template<class T>
Array<T>* Array<T>::Merge(Array<T> arr2) {
	int i = 0, j = 0, k = 0;
	Array* arr3 = new Array(length+arr2.length);

	while (i < length && j < arr2.length) {
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}

	for (; i < length; i++)
		arr3->A[k++] = A[i];

	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];

	arr3->length = length + arr2.length;

	return arr3;
}

template<class T>
void Array<T>::findDuplicates() {

	Array<int> H = new Array<int>(Max());

	for (int i = 0; i < H.length; i++)
	{
		H.A[i] = 0;
		std::cout << H.A[i] << "\t";
	}
	std::cout << std::endl;

	for (int i = 0; i < length; i++) {
		H.A[A[i]]++;
		
	}

	/*
	for (int i = 0; i < H->length; i++)
		if (H->A[i] > 1)
			std::cout << "The Number " << i << "is appearing " << H->A[i] << " times!\n";
	*/
}