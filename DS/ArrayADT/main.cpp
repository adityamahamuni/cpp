#include "ArrayADT.cpp"

int main() {
	Array<int> arr1(20);


	arr1.Insert(0, 3);
	arr1.Insert(1, 6);
	arr1.Insert(2, 8);
	arr1.Insert(3, 8);
	arr1.Insert(4, 10);
	arr1.Insert(5, 12);
	arr1.Insert(6, 15);
	arr1.Insert(7, 15);
	arr1.Insert(8, 15);
	arr1.Insert(9, 20);

	//arr1.displayArr();

	arr1.findDuplicates();
}
