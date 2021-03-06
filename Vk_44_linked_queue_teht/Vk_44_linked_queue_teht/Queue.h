#pragma once
#include "Node.h"
#include "Utility.h"
typedef int Queue_entry;

class Queue {
public:
	//  standard Queue methods
	Queue();
	bool empty() const; // valmis
	Error_code append(const Queue_entry &item);
	Error_code serve();
	Queue_entry retrieve(Queue_entry &item) const;
	//  safety features for linked structures
	~Queue(); // valmis
	Queue(Queue &original);
	void operator =(const Queue &original);
protected:
	Node *front, *rear;
};