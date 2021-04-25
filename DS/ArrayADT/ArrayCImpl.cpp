#include<stdio.h>
#include<stdlib.h>

struct Array {
	int A[20];
	int size;
	int length;
};

void displayArr(struct Array arr) {
	int i;
	printf("Elements are : \n");

	for (i = 0; i < arr.length; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

void Append(struct Array* arr, int x) {

	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}

void Insert(struct Array* arr, int index, int x) {

	int i;
	if (index >= 0 && index <= arr->length) {
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
	else {
		printf("Index Invalid.\n");
	}
}

int Delete(struct Array* arr, int index) {

	int i, temp;
	if (index >= 0 && index <= arr->length) {
		temp = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
		return temp;
	}
	else {
		printf("Index Invalid.\n");
	}

	return 0;

}

int LinearSearch(struct Array* arr, int elem) {

	int i = 0;
	for (i = 0; i < arr->length; i++) {
		if (arr->A[i] == elem)
			return i;
	}
	return -1;
}

int BinarySearch(struct Array* arr, int key) {
	int low = 0;
	int high = arr->length - 1;
	int mid = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid])
			high = mid - 1;
		else if (key > arr->A[mid])
			low = mid + 1;
	}
	return -1;
}

int BinarySearchRecursive(struct Array* arr, int low, int high, int key) {

	int mid = 0;
	if (low <= high) {
		mid = (low + high) / 2;

		if (key == arr->A[mid])
			return mid;
		else if (key < arr->A[mid]) {
			return BinarySearchRecursive(arr, low, mid - 1, key);
		}
		else if (key > arr->A[mid])
			return BinarySearchRecursive(arr, mid + 1, high, key);
	}
	return -1;
}

int getElement(struct Array arr, int index) {
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	else {
		printf("Index out of Bounds.\n");
		return -1;
	}
}

void setElement(struct Array* arr, int index, int x) {
	if (index >= 0 && index < arr->length)
		arr->A[index] = x;
	else {
		printf("Index out of Bounds.\n");
	}
}

int max(struct Array arr) {
	int i = 0, max = arr.A[0];

	for (i = 1; i < arr.length; i++)
		if (arr.A[i] > max)
			max = arr.A[i];

	return max;
}

int min(struct Array arr) {
	int i = 0, min = arr.A[0];

	for (i = 1; i < arr.length; i++)
		if (arr.A[i] < min)
			min = arr.A[i];

	return min;
}

int sum(struct Array arr) {
	int total = 0, i = 0;
	for (i = 0; i < arr.length; i++)
		total += arr.A[i];

	return total;
}

float avg(struct Array arr) {
	float total = 0;
	total = static_cast<float>(sum(arr));
	return total / arr.length;
}

void ReverseArray(struct Array* arr) {
	int i = 0, j = 0;
	int temp = 0;
	for (i = 0, j = arr->length - 1; i < j; i++, j--) {
		temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
	}
	printf("Reversed Array :- \n");
	displayArr(*arr);
}

void LeftRotation(struct Array* arr) {
	int i = 0;
	int temp = arr->A[0];
	for (i = 0; i < arr->length; i++) {
		arr->A[i] = arr->A[i + 1];
	}
	arr->A[arr->length - 1] = temp;
}

void RightRotation(struct Array* arr) {
	int i = 0;
	int temp = arr->A[arr->length - 1];
	for (i = arr->length - 1; i >= 0; i--) {
		arr->A[i] = arr->A[i - 1];
	}
	arr->A[0] = temp;
}

bool isSorted(struct Array arr) {
	int i = 0;

	for (i = 0; i < arr.length - 1; i++) {
		if (arr.A[i] > arr.A[i + 1])
			return false;
	}
	return true;
}

struct Array* Merge(struct Array* arr1, struct Array* arr2) {
	int i = 0, j = 0, k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length) {
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}

	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];

	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;

	return arr3;
}
