
//DLL Palindrome

#include <iostream>
#include <string>

using namespace std;

struct Node 
{
	char data;
	Node* next;
	Node* prev;

	Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList 
{
private:
	Node* head;

public:
	DoublyLinkedList() : head(nullptr) {}

	void print() 
	{
		Node* temp = head;
		while (temp) 
		{
			cout << temp->data;
			temp = temp->next;
		}
	}

	// adds the input to the node
	void addNode(char data)
	{
		Node* newNode = new Node(data);
		if (head == nullptr) 
		{
			head = newNode;
		}
		else 
		{
			Node* temp = head;
			while (temp->next) 
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
	}

	// Function that compares the original linked list to the reversed linked list
	bool isEqual(DoublyLinkedList& other) 
	{
		Node* current = head;
		Node* temp = other.head;

		while (current && temp) 
		{
			if (current->data != temp->data) 
			{
				return false;
			}
			current = current->next;
			temp = temp->next;
		}

		return true;
	}

	//reverses the input and places it in temp
	void reverse() 
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) 
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != nullptr) 
		{
			head = temp->prev;
		}
	}

};

// removes spaces and capitals from the input and returns it
string cleanInput(const string& input) 
{
	string newInput;
	for (char c : input) 
	{
		if (!isspace(c)) 
		{
			newInput += tolower(c);
		}
	}
	return newInput;
}

int main() 
{
	string input;
	cout << "Enter a word or sentence: ";
	cin >> input;

	string cleanedInput = cleanInput(input);

	DoublyLinkedList originalList;
	for (char c : cleanedInput) 
	{
		originalList.addNode(c);
	}

	DoublyLinkedList reversedList = originalList;
	reversedList.reverse();

	if (originalList.isEqual(reversedList)) 
	{
		cout << input << " is a palindrome." << endl;
	}
	else 
	{
		cout << input << " is not a palindrome." << endl;
	}

	return 0;
}