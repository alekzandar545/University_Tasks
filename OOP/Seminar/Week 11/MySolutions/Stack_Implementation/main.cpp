#include <iostream>
#include "Sloppy_Stack.h"

int main()
{
	Stack<int> q;
	q.Push(3);
	q.Push(5);
	q.Push(10);

	std::cout << q.Peek() << '\n'; //3
	q.Pop();

	std::cout << q.Peek() << '\n'; //5
	q.Pop();

	std::cout << q.Peek() << '\n'; //10
	q.Pop();

	std::cout << q.isEmpty() << '\n'; //1	
}