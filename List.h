//
//

#ifndef LIST_H
#define LIST_H
#include "Drone.h"
#include <iostream>

using namespace std;

class List {
public:

	/**
	 * Create an empty list of drones
	 */
	List();

	/* big three */
	List(const List& other);

	List& operator=(const List& rhs);

	~List();

	void insert(Drone elem);

	void remove(Drone elem);

	void clear();

	int size() const;


	Drone& operator[](int index);



	const Drone& operator[](int index) const;

	friend ostream& operator<<(ostream& out, const List& list);

private:
	struct Node {
		Drone data;
		Node* next;

		Node(Drone data, Node* next);
	};

	Node* head;
	int count;
};

ostream& operator<<(ostream& out, const List& list);

#endif LIST_H
