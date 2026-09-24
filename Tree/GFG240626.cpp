// Delete from BST

// Given a binary search tree and a node value x. Delete the node with the given value x from the tree.
// If no node with value x exists, then do not make any change. 

// Return the root of the tree after deleting the node with value x.

// Note: You may return any valid BST after deleting the specified node.
//       The driver code will print true if the resulting tree is a valid BST after deletion, and false otherwise.





/* Structure of a Binary Search Tree node
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
}; */
class Solution {
    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

public:
    Node* delNode(Node* root, int x) {
        if (root == nullptr) return nullptr;

        if (x < root->data) {
            root->left = delNode(root->left, x);
        } else if (x > root->data) {
            root->right = delNode(root->right, x);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delNode(root->right, temp->data);
        }
        return root;
    }
};