#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include <iterator>

//template funtion to display any deque
template <typename T>
void disp(const std::deque<T>& d) {
	std::cout << "[ ";

	for (const auto& item : d)
		std::cout << item << " ";
	std::cout << " ]" << std::endl;
}

void test_1() {
	std::cout << "\nTest1 ===========================" << std::endl;

	std::deque<int> d{ 1, 2, 3, 4, 5 };
	disp(d);

	d = { 2, 4, 5, 6 };
	disp(d);

	std::deque<int> d1(10, 100 );
	disp(d1);

	d[0] = 100;
	d.at(1) = 200;
	disp(d);
}

void test_2() {
	std::cout << "\nTest2 ===========================" << std::endl;

	std::deque<int> d{ 0,0,0 };
	disp(d);

	d.push_back(10);
	d.push_back(20);
	disp(d);

	d.push_front(100);
	d.push_front(200);
	disp(d);

	std::cout << "Front: " << d.front() << std::endl;
	std::cout << "Back: " << d.back() << std::endl;
	std::cout << "Size: " << d.size() << std::endl;

	d.pop_back();
	d.pop_front();
	disp(d);
}

void test_3() {
	// Insert all even numbers into the back of a deque and all odd numbers to the front
	std::cout << "\nTest3 ===========================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::deque<int> d;

	for (const auto& item : vec) {
		if (item % 2 == 0)
			d.push_back(item);
		else
			d.push_front(item);
	}

	disp(d);
}

void test_4() {
	std::cout << "\nTest4 ===========================" << std::endl;
	
	// Push front vs back ordering
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::deque<int> d;

	for (const auto& item : vec) {
		d.push_front(item);
	}

	disp(d);

	d.clear();

	for (const auto& item : vec) {
		d.push_back(item);
	}

	disp(d);
}

void test_5() {
	std::cout << "\nTest5 ===========================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::deque<int> d;

	std::copy(vec.begin(), vec.end(), std::front_inserter(d));
	disp(d);

	d.clear();

	std::copy(vec.begin(), vec.end(), std::back_inserter(d));
	disp(d);
}
/*
int main() {

	test_1();
	test_2();
	test_3();
	test_4();
	test_5();

	return 0;
}*/