// 1.Array to BST

// Given a sorted array arr[]. Convert it into a Height Balanced Binary Search Tree (BST) and return the root of the BST.
// Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

// Note: You can return any BST, the driver code will check the BST, and print true if it is a Height-balanced BST else print false.

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* ite(vector<int>& arr, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        Node* node = new Node(arr[mid]);
        node->left = ite(arr, left, mid - 1);
        node->right = ite(arr, mid + 1, right);
        return node;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        return ite(arr, 0, arr.size() - 1);
    }
};



// 2. Clone List with Next and Random


// Given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list,
// and a random pointer that points to the random node of the linked list.
//    ->Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node.
//    ->Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list structure.
//    ->None of the pointers in the new list should point to nodes in the original list and original linked list should remain unchanged.
// Return the head of the copied linked list.
// Each node of the linked list is represented as a pair of [val, random_index] where:
//    ->val represents node.data.
//    ->random_index (1-based index) represents the index of the node that the random pointer of the current node points to, or NULL if it does not point to any node.


/* Structure of Linked List Node
class Node {
	public:
	int data;
	Node* next;
	Node* random;
	
	Node(int x) {
		data = x;
		next = random = nullptr;
	}
}; 
*/


class Solution {
	public:
	Node* cloneLinkedList(Node* head) {
		
		if (!head)
			return nullptr;
		Node* curr = head;
		
		while (curr) {
			Node* copy = new Node(curr->data);
			
			copy->next = curr->next;
			curr->next = copy;
			
			curr = copy->next;
		}
		curr = head;
		while (curr) {
			if (curr->random) {
				curr->next->random = curr->random->next;
			}
			curr = curr->next->next;
		}
		Node* copyHead = head->next;
		curr = head;
		while (curr) {
			Node* copy = curr->next;
			curr->next = copy->next;
			if (copy->next) {
				copy->next = copy->next->next;
			}
			curr = curr->next;
		}
		return copyHead;
	}
};
