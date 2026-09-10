// Implement a Stack using an Array, where the size of the array, n is given.
// The Stack must support the following operations:

// (i) push(x): Insert an element x at the top of the stack.
// (ii) pop(): Remove the element from the top of the stack.
// (iii) peek(): Return the top element if not empty, else -1.
// (iv) isEmpty(): Return true if the stack is empty else return false.
// (v) isFull(): Return true if the stack is full else return false.




class myStack {
	private:
	int* arr;
	int top;
	int capacity;
	
	public:
	myStack(int n) {
		capacity = n;
		arr = new int[n];
		top = -1;
	}
	
	bool isEmpty() {
		return top == -1;
	}
	
	bool isFull() {
		return top == capacity - 1;
	}
	
	void push(int x) {
		if (!isFull()) {
			arr[++top] = x;
		}
	}
	
	void pop() {
		if (!isEmpty()) {
			top--;
		}
	}
	
	int peek() {
		if (isEmpty()) {
			return - 1;
		}
		return arr[top];
	}
};
