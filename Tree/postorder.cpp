// Given the root of a Binary Tree, return its Postorder Traversal.


/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
private:
    void porder(Node* temp, vector<int>& ret) {
        if (temp == nullptr) {
            return;
        }
        porder(temp->left, ret);
        porder(temp->right, ret);
        ret.push_back(temp->data);
    }

public:
    vector<int> postOrder(Node* root) {
        vector<int> ret;
        porder(root, ret);
        return ret;
    }
};