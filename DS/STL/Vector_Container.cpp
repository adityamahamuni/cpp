#include<iostream>
#include<algorithm>
#include<vector>
/*
class Person {

	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	std::string name;
	int age;
public:
	Person() = default;
	Person(std::string name, int age) : name(name), age(age){}

	bool operator<(const Person& rhs)const {
		return this->age < rhs.age;
	}

	bool operator==(const Person& rhs) const {
		return (this->name == rhs.name && this->age == rhs.age);
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.name << ":" << p.age;
	return os;
}

void display2(const std::vector<int>& vec) {
	std::cout << "[ ";
	std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });
	std::cout << " ]" << std::endl;
}


// Template function to display any vector
template <typename T>
void display_t(const std::vector<T>& vec) {
	std::cout << "[ ";
	for (const auto& elem : vec)
		std::cout << elem << " ";
	std::cout << " ]"<<std::endl;
}

void test_first() {
	std::cout << "\nTest1=====================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display_t(vec);

	std::vector<int> vec1{ 10, 100 };
	display_t(vec1);
}

void test_second() {
	std::cout << "\nTest2=====================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display_t(vec);

	std::cout << "Vec Size: " << vec.size() << std::endl;
	std::cout << "Vec Max Size: " << vec.max_size() << std::endl;
	std::cout << "Vec Capacity: " << vec.capacity() << std::endl;

	vec.push_back(6);
	display_t(vec);

	std::cout << "Vec Size: " << vec.size() << std::endl;
	std::cout << "Vec Max Size: " << vec.max_size() << std::endl;
	std::cout << "Vec Capacity: " << vec.capacity() << std::endl;

	vec.shrink_to_fit();
	display_t(vec);

	std::cout << "Vec Size: " << vec.size() << std::endl;
	std::cout << "Vec Max Size: " << vec.max_size() << std::endl;
	std::cout << "Vec Capacity: " << vec.capacity() << std::endl;

	vec.reserve(100);
	display_t(vec);

	std::cout << "Vec Size: " << vec.size() << std::endl;
	std::cout << "Vec Max Size: " << vec.max_size() << std::endl;
	std::cout << "Vec Capacity: " << vec.capacity() << std::endl;

}

void test_third() {
	std::cout << "\nTest3=====================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display_t(vec);

	vec[0] = 100;
	vec.at(1) = 200;

	display_t(vec);
}

void test_four() {
	std::cout << "\nTest4=====================" << std::endl;

	std::vector<Person> stooges;

	Person p1{ "Aditya", 21 };
	display_t(stooges);

	stooges.push_back(p1);
	display_t(stooges);

	stooges.push_back(Person{ "Aditya", 21 });
	display_t(stooges);

	stooges.emplace_back("Aditya Mahamuni", 22);
	display_t(stooges);
}

void test_five() {
	std::cout << "\nTest5=====================" << std::endl;
	
	std::vector<Person> stooges{ {"Adi", 21}, {"aditya", 22} };

	display_t(stooges);

	std::cout << "\nFront" << stooges.front() << std::endl;
	std::cout << "\nBack" << stooges.back() <<std::endl;

	stooges.pop_back();
	display_t(stooges);
}

void test_six() {
	std::cout << "\nTest5=====================" << std::endl;

	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	display_t(vec);

	vec.clear();
	display_t(vec);

	vec = { 1,2,3,4,5,6,7,8,9,10 };
	display_t(vec);

	vec.erase(vec.begin(), vec.begin() + 2);
	display_t(vec);

	vec = { 1,2,3,4,5,6,7,8,9,10 };
	// erase all even numbers

	auto it = vec.begin();
	while (it != vec.end()) {
		if (*it % 2 == 0)
			vec.erase(it);
		else
			it++;
	}
	display_t(vec);
}

int main() {

	test_first();
	test_second();
	test_third();
	test_four();
	test_five();
	test_six();

	return 0;
}*/