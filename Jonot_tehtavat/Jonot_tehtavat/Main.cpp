#include <iostream>
#include "Queue.h"
#include "Utility.h"

bool do_command(char c, Queue &test_queue);
void help();
// using namespace std;

int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
the class Extended_queue.
Uses: The class Extended_queue and the functions introduction,
get_command, and do_command.
*/

{
	Queue q;
	Queue_entry en;
	char x = 'x';
	char y = 'y';
	char test;
/* TEHT 2 a)
	q.append('a');
	q.retrieve(x);
	std::cout << x << std::endl;
	q.serve();
	q.append('b');
	q.retrieve(x);
	std::cout << x << std::endl;
	q.serve();
	q.append('c');
	q.retrieve(x);
	std::cout << x << std::endl;
	q.append('d');
	q.retrieve(x);
	std::cout << x << std::endl;
	q.serve();
	q.retrieve(x);
	std::cout << x << std::endl;
	*/

	/*TEHT 2b)
	q.append('a');
	q.append('b');
	q.retrieve(x);
	std::cout << x << std::endl;
	q.serve();
	std::cout << x << std::endl;
	q.append('c');
	std::cout << x << std::endl;
	q.append(x);
	std::cout << x << std::endl;
	q.serve();
	std::cout << x << std::endl;
	q.serve();
	std::cout << x << std::endl;
	*/
	/*TEHT 2c)
	q.append('a');
	q.retrieve(en);
	std::cout << en << std::endl;
	x = 'b';
	q.retrieve(en);
	std::cout << en << std::endl;
	q.append('x');
	q.retrieve(en);
	std::cout << en << std::endl;
	q.retrieve(y);
	std::cout << y << std::endl;
	q.serve();
	q.retrieve(en);
	std::cout << en << std::endl;
	q.append(x);
	q.retrieve(en);
	std::cout << en << std::endl;
	q.serve();
	q.retrieve(en);
	std::cout << en << std::endl;
	q.append(y);
	q.retrieve(en);
	std::cout << en << std::endl;
	*/
	system("pause");



	/*
	Queue test;
	help();
	int i = 1;

	test.append(i);
	
	while (do_command(test.get_command(), test));
	*/
}

void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
command that the user may enter.
*/

{
	std::cout << std::endl
		<< "This program allows the user to enter one command" << std::endl
		<< "(but only one) on each input line." << std::endl
		<< "For example, if the command S is entered, then" << std::endl
		<< "the program will serve the front of the queue." << std::endl
		<< std::endl

		<< " The valid commands are:" << std::endl
		<< "A - Append the next input character to the extended queue" << std::endl
		<< "S - Serve the front of the extended queue" << std::endl
		<< "R - Retrieve and print the front entry." << std::endl
		<< "# - The current size of the extended queue" << std::endl
		<< "C - Clear the extended queue (same as delete)" << std::endl
		<< "P - Print the extended queue" << std::endl
		<< "H - This help screen" << std::endl
		<< "Q - Quit" << std::endl

		<< "Press <Enter> to continue." << std::flush;

	char c;
	do {
		std::cin.get(c);
	} while (c != '\n');
}

bool do_command(char c, Queue &test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
*/

{
	bool continue_input = true;
	Queue_entry x;

	switch (c) {
	case 'r':
		if (test_queue.retrieve(x) == underflow)
			std::cout << "Queue is empty." << std::endl;
		else
			std::cout << std::endl
			<< "The first entry is: " << x
			<< std::endl;
		break;

	case 'q':
		std::cout << "Extended queue demonstration finished." << std::endl;
		continue_input = false;
		break;
		//  Additional cases will cover other commands.
	}
	return continue_input;
}
