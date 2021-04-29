#include<iostream>
#include"Queue.h"

int main() {
	std::cout << " *******Integer Queue******** " << std::endl;
	Queue<int> q(10);
	if (q.isEmpty())
		std::cout << "Queue is Empty." << std::endl;

	q.enqueue(5);
	q.enqueue(9);
	q.enqueue(10);

	std::cout << "Elements of Queue : " << std::endl;
	q.display();

	std::cout << "Removed Element : " << q.dequeue() << std::endl;

	std::cout << "Elements of Queue : " << std::endl;
	q.display();


	std::cout << " *******Char Queue******** " << std::endl;
	Queue<char> qStr(10);
	if (qStr.isEmpty())
		std::cout << "Queue is Empty." << std::endl;

	qStr.enqueue('A');
	qStr.enqueue('B');
	qStr.enqueue('C');

	std::cout << "Elements of Queue : " << std::endl;
	qStr.display();

	std::cout << "Removed Element : " << qStr.dequeue() << std::endl;

	std::cout << "Elements of Queue : " << std::endl;
	qStr.display();

	std::cout << " *******Double Queue******** " << std::endl;
	Queue<double> qDb(10);
	if (qDb.isEmpty())
		std::cout << "Queue is Empty." << std::endl;

	qDb.enqueue(20.2331);
	qDb.enqueue(1231.12312);
	qDb.enqueue(3241.332);

	std::cout << "Elements of Queue : " << std::endl;
	qDb.display();

	std::cout << "Removed Element : " << qDb.dequeue() << std::endl;

	std::cout << "Elements of Queue : " << std::endl;
	qDb.display();


	std::cout << " *********Queue using Stacks************* " << std::endl;
	QueueStk<int> qStk(10);
	qStk.enqueue(10);
	qStk.enqueue(20);
	qStk.enqueue(30);

	std::cout << "Elements of Queue : " << std::endl;
	qStk.display();

	std::cout << "Removed Element : " << qStk.dequeue() << std::endl;
	std::cout << "Removed Element : " << qStk.dequeue() << std::endl;

	std::cout << "Elements of Queue : " << std::endl;
	qStk.display();


	return 0;
}