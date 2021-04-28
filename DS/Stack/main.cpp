#include<iostream>
#include"Stack.h"

int main() {

	Stack<int> st(5);

	if (st.isEmpty())
		std::cout << "Stack is Empty" << std::endl;

	st.push(10);
	st.push(30);
	st.push(50);

	std::cout << "Elements in the Stack : " << std::endl;
	st.display();

	std::cout << "Element Removed : " << st.pop() << std::endl;
	st.display();

	std::cout << "Top Element : " << st.peek() << std::endl;

	st.push(70);
	st.push(90);

	if (st.isFull())
		std::cout << "Stack is Full." << std::endl;

	return 0;

}