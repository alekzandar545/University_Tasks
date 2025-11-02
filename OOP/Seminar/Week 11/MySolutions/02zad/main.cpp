#include "priorityQueue.hpp"

int main()
{
	PriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.

	q.Push('A',0); //adds A with lowest priority: 0
	q.Push('B',3);
	q.Push('C',2);
	q.Push('D',2);
	q.Push('E',1);

	//q.Push('F', 5); //error! No such priority!

	std::cout << q.Peek(); // B
	q.Pop();

	std::cout << q.Peek(); // C
	q.Pop();

	std::cout << q.Peek(); // D
	q.Pop();

	std::cout << q.Peek(); // E
	q.Pop();

	std::cout << q.Peek(); // A
	q.Pop();
}