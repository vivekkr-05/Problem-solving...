// Check for BST

// Given a binary tree, check whether it is a Binary Search Tree (BST) or not.
// A binary tree is considered a BST if it satisfies the following properties:
// All nodes in the left subtree of a node have values less than the node's value.
// All nodes in the right subtree of a node have values greater than the node's value.
// Both the left and right subtrees are also Binary Search Trees.
// Return true if the given binary tree is a BST; otherwise, return false.


// Structure of a Binary Search Tree node

class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; 

class Solution {
	public:
	bool isValidBST(Node* node, long long minVal, long long maxVal) {
		if (node == nullptr)
			return true;
		if (node->data <= minVal || node->data >= maxVal)
			return false;
		return isValidBST(node->left, minVal, node->data) && isValidBST(node->right, node->data, maxVal);
	}
	
	bool isBST(Node* root) {
		return isValidBST(root, LLONG_MIN, LLONG_MAX);
	}
};
