// Merge Two BSTs

// Given the roots r1 and r2 of two Binary Search Trees (BSTs),
// merge the elements of both trees into a single sorted array and return it.

// The returned array should contain all the elements from both BSTs, including duplicate values if they are present.

//Structure of a Binary Search Tree node

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

class Solution {
private:
    void inorder(Node* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->data);
        inorder(root->right, nums);
    }

    vector<int> mergeSortedArrays(const vector<int>& a, const vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                result.push_back(a[i++]);
            } else {
                result.push_back(b[j++]);
            }
        }
        while (i < a.size()) result.push_back(a[i++]);
        while (j < b.size()) result.push_back(b[j++]);
        return result;
    }

public:
    vector<int> merge(Node* r1, Node* r2) {
        vector<int> nums1, nums2;
        inorder(r1, nums1);
        inorder(r2, nums2);
        return mergeSortedArrays(nums1, nums2);
    }
};