#include<set>
#include<iostream>

class Human {
	friend std::ostream& operator<<(std::ostream& os, const Human& p);
	std::string name;
	int age;

public:
	Human() :name{"Unknown"}, age{0}{}
	Human(std::string, int age):name{name}, age{age}{}

	bool operator<(const Human& rhs) const {
		return this->age < rhs.age;
	}

	bool operator==(const Human& rhs) const {
		return (this->name == rhs.name && this->age == rhs.age);
	}
};

std::ostream& operator<<(std::ostream& os, const Human& p) {
	os << p.name << " : " << p.age;
	return os;
}

template <typename T>
void display_set(const std::set<T>& t) {
	std::cout << "[ ";
	for (const auto& elem : t) {
		std::cout << elem << " ";
	}
	std::cout << " ]" << std::endl;
}

void test_one() {
	std::cout << "\n Test1 ==========================" << std::endl;
	std::set<int> s1{ 1,4,3,5,2 };
	display_set(s1);

	s1 = { 1,2,3,1,1,2,2,3,3,4,5 };
	display_set(s1);

	s1.insert(0);
	s1.insert(10);

	display_set(s1);

	if (s1.count(10))
		std::cout << "10 is in the set" << std::endl;
	else
		std::cout << "10 is not in the set!" << std::endl;

	auto it = s1.find(5);
	if (it != s1.end())
		std::cout << "Found: " << *it << std::endl;

	s1.clear();
	display_set(s1);
}

void test_two() {
	std::cout << "\n Test2 ==========================" << std::endl;

	std::set<Human> stooges{
		{"Adi", 21}, {"aditya", 21}
	};

	display_set(stooges);

	stooges.emplace("Aditya Mahamuni", 22);
	display_set(stooges);

	stooges.emplace("adi", 22);
	display_set(stooges);

	auto it = stooges.find(Human{ "adi", 22 });
	if (it != stooges.end())
		stooges.erase(it);

	display_set(stooges);

	it = stooges.find(Human("XXXX", 22));

	if (it != stooges.end())
		stooges.erase(it);

	display_set(stooges);
}

/*
int main() {

	test_one();
	test_two();

	return 0;
}*/