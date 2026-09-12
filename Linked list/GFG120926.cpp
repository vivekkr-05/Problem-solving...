// Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list.
// Return the head of the modified linked list.

/* Structure of a Linked List node
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
public:
    Node *compute(Node *head) {
        if (!head || !head->next) return head;

        head->next = compute(head->next);

        if (head->next->data > head->data) {
            return head->next;
        }
        return head;
    }
};
