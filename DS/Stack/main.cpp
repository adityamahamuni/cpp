#include<iostream>
#include"Stack.h"


bool parenthesisMatch(std::string str) {
	Stack<char> stk(str.length());

	for (auto& ch : str) {
		if (ch == '(' || ch == '[' || ch == '{')
			stk.push(ch);
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (stk.isEmpty())
				return false;
			else {
				char c;
				c = stk.pop();
				if ((c == '(' && ch != ')') || (c == '[' && ch != ']') || (c == '{' && ch != '}'))
					return false;
			}
		}
	}
	if (stk.isEmpty())
		return true;

	return false;
}

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

	std::string par = "{[([A-] * [A+b]) \ e}";

	if (parenthesisMatch(par))
		std::cout << "Parenthesis are in Proper Order." << std::endl;
	else
		std::cout << "Parenthesis are not in proper order." << std::endl;

	return 0;

}