#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>


class Person {
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	std::string name;
	int age;
public:
	Person(): name{"Unknown"}, age{0}{}
	Person(std::string name, int age): name{name}, age{age}{}

	bool operator<(const Person& rhs) const {
		return this->age < rhs.age;
	}

	bool operator==(const Person& rhs) const {
		return (this->name == rhs.name && this->age == rhs.age);
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.name << " : " << p.age;
	return os;
}

template <typename T>
void show(const std::list<T>& l) {
	std::cout << "[ ";
	for (const auto& elem : l) {
		std::cout << elem << " ";
	}
	std::cout << " ]" << std::endl;
}

void one() {
	std::cout << "\n Test1 ==============================" << std::endl;

	std::list<int> l{ 1, 2, 3, 4, 5 };
	show(l);

	std::list<std::string> l1;
	l1.push_back("Back");
	l1.push_front("Front");
	show(l1);

	std::list<int> l2;
	l2 = { 1,2,3,4,5,6,7,8,9,10 };
	show(l2);

	std::list<int> l3(10, 100);
	show(l3);
}

void two() {
	std::cout << "\n Test2 ==============================" << std::endl;

	std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	show(l);

	std::cout << "Size: " << l.size() << std::endl;
	std::cout << "Front: " << l.front() << std::endl;
	std::cout << "Back: " << l.back() << std::endl;

	l.clear();
	show(l);

	std::cout << "Size: " << l.size() << std::endl;


}

void three() {
	std::cout << "\n Test3 ==============================" << std::endl;

	std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	show(l);

	l.resize(5);
	show(l);

	l.resize(10);
	show(l);

	std::list<Person> persons;
	persons.resize(5);
	show(persons);
}

void four() {
	std::cout << "\n Test4 ==============================" << std::endl;

	std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	show(l);

	auto it = std::find(l.begin(), l.end(), 5);
	if (it != l.end())
		l.insert(it, 100);

	show(l);

	std::list<int> l2{ 1000, 2000, 3000 };
	l.insert(it, l2.begin(), l2.end());
	show(l);

	std::advance(it, -4);
	l.erase(it);
	show(l);
}

void five() {
	std::cout << "\n Test5 ==============================" << std::endl;

	std::list<Person> p;
	show(p);
}
/*
int main() {

	one();
	two();
	three();
	four();
	five();

	return 0;
}

*/