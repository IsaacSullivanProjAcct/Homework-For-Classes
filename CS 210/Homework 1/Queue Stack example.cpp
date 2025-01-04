//
////Queue-Heap Palindrome
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Stack {
//private:
//    char* arr;
//    int top;
//    int capacity;
//
//public:
//    Stack(int size)
//    {
//        arr = new char[size];
//        capacity = size;
//        top = -1;
//    }
//
//    ~Stack() {
//        delete[] arr;
//    }
//
//    void push(char c) 
//    {
//        if (top < capacity - 1) 
//        {
//            arr[++top] = c; 
//        }
//    }
//
//    char pop() 
//    {
//        if (!isEmpty()) 
//        {
//            return arr[top--];
//        }
//        cout << "stack underflow";
//    }
//
//    bool isEmpty() const 
//    {
//        return top == -1;
//    }
//};
//
//
//class Queue {
//private:
//    char* arr;
//    int front;
//    int rear;
//    int capacity;
//
//public:
//    Queue(int size) : capacity(size), front(0), rear(0) {
//        arr = new char[capacity];
//    }
//
//    ~Queue() {
//        delete[] arr;
//    }
//
//    void enqueue(char c) {
//        if ((rear + 1) % capacity != front) {
//            arr[rear] = c;
//            rear = (rear + 1) % capacity;
//        }
//    }
//
//    char dequeue() {
//        if (!isEmpty()) {
//            char c = arr[front];
//            front = (front + 1) % capacity;
//            return c;
//        }
//        cout << "empty queue";
//    }
//
//    bool isEmpty() const 
//    {
//        return front == rear;
//    }
//};
//
//// removes spaces and capitals from the input and returns it
//string cleanInput(const string& input)
//{
//    string newInput;
//    for (char c : input)
//    {
//        if (!isspace(c))
//        {
//            newInput += tolower(c);
//        }
//    }
//    return newInput;
//}
//
//// Function to check if the string is a palindrome
//bool isPalindrome(const string& cleanedInput) 
//{
//    Stack stack(cleanedInput.length());
//    Queue queue(cleanedInput.length());
//
//    // Adds characters to both the stack and the queue
//    for (char c : cleanedInput) {
//        stack.push(c);
//        queue.enqueue(c);
//    }
//
//    // Compares characters from the stack and queue
//    while (!stack.isEmpty() && !queue.isEmpty()) {
//        if (stack.pop() != queue.dequeue()) {
//            return false;
//        
//        }
//    }
//    return true;
//}
//
//int main() {
//    string input;
//    cout << "Enter a word or sentence: ";
//    getline(cin, input);
//
//    string cleanedInput = cleanInput(input);
//
//    if (isPalindrome(cleanedInput)) {
//        cout << input << " is a palindrome." << endl;
//    }
//    else 
//    {
//        cout << input << " is not a palindrome." << endl;
//    }
//
//    return 0;
//}