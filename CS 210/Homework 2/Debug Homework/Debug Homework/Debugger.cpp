#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};
class LinkedList {
public:
	Node* head;
	LinkedList() : head(nullptr) {}
	void append(int value) {
		if (!head) {
			head = new Node(value);
			return;
		}
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new Node(value);
	}
	void print() {
		Node* temp = head;
		while (temp) {
			std::cout << temp->data << " -> ";
			temp = temp->next;
		}
		std::cout << "NULL\n";
	}
};

//An interweave function that will take a node from LL1 and then LL2 and repeat until one runs out
//Before consuming all nodes from the other
LinkedList interweave(LinkedList& l1, LinkedList& l2) {
	LinkedList result;
	Node* t1 = l1.head;
	Node* t2 = l2.head;
	while (t1 != nullptr || t2 != nullptr) {
		if (t1 != nullptr) {
			result.append(t1->data);
			t1 = t1->next;
		}
		if (t2 != nullptr) {
			result.append(t2->data);
			t2 = t2->next;
		}
	}
	return result;
}
// DO NOT MODIFY MAIN at all
int main() {
	// Test 1: Both lists are of equal length.
	cout << "Test case 1: " << endl;
	LinkedList l1;
	LinkedList l2;
	l1.append(1);
	l1.append(2);
	l1.append(3);
	l2.append(4);
	l2.append(5);
	l2.append(6);
	interweave(l1, l2).print(); // Expect: 1 -> 4 -> 2 -> 5 -> 3 -> 6 -> NULL
	// Test 2: First list is longer.
	cout << "Test case 2: " << endl;
	l1.append(7);
	interweave(l1, l2).print(); // Expect: 1 -> 4 -> 2 -> 5 -> 3 -> 6 -> 7 -> NULL
	// Test 3: Second list is longer.
	cout << "Test case 3: " << endl;
	LinkedList l3;
	LinkedList l4;
	l3.append(1);
	l3.append(2);
	l4.append(3);
	l4.append(4);
	l4.append(5);
	interweave(l3, l4).print(); // Expect: 1 -> 3 -> 2 -> 4 -> 5 -> NULL
	// Test 4: First list empty
	cout << "Test case 4: " << endl;
	LinkedList l5;
	LinkedList l6;
	l6.append(7);
	l6.append(8);
	l6.append(9);
	interweave(l5, l6).print(); // Expect: 7 -> 8 -> 9 -> NULL
	// Test 5: Second list empty
	cout << "Test case 5: " << endl;
	LinkedList l7;
	LinkedList l8;
	l7.append(10);
	l7.append(11);
	l7.append(12);
	interweave(l7, l8).print(); // Expect: 10 -> 11 -> 12 -> NULL
	// Test 6: Both lists are empty.
	cout << "Test case 6: " << endl;
	LinkedList l9;
	LinkedList l10;
	interweave(l9, l10).print(); // Expect: NULL
	// Test 7: First list has one element, second list is empty.
	cout << "Test case 7: " << endl;
	LinkedList l11;
	LinkedList l12;
	l11.append(13);
	interweave(l11, l12).print(); // Expect: 13 -> NULL
	// Test 8: test 7 but flipped
	cout << "Test case 8: " << endl;
	LinkedList l13;
	LinkedList l14;
	l14.append(14);
	interweave(l13, l14).print(); // Expect: 14 -> NULL
	// Test 9: Both lists have one element
	cout << "Test case 9: " << endl;
	LinkedList l15;
	LinkedList l16;
	l15.append(15);
	l16.append(16);
	interweave(l15, l16).print(); // Expect: 15 -> 16 -> NULL
	// Test 10: two different sized lists
	cout << "Test case 10: " << endl;
	LinkedList l17, l18;
	l17.append(1);
	l17.append(3);
	l17.append(5);
	l17.append(7);
	l18.append(2);
	l18.append(4);
	l18.append(6);
	interweave(l17, l18).print(); // Expect: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
		return 0;
}