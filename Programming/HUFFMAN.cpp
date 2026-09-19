// Huffman Encoding

// Given a string s of distinct characters and their corresponding frequency f[ ] i.e. character s[i] has f[i] frequency.
// Build the Huffman tree and return all the huffman codes in preorder traversal of the tree.

// Note: While merging, if two nodes have the same value (frequency),
//       then the node whose subtree contains the character that appears earlier
//       in the string s will be taken on the left of the Binary Tree and the other one to the right.
//       Otherwise, the node with smaller value will be taken on the left of the subtree and the other one to the right.

class Solution {
    struct Node {
        char data;
        int freq;
        int index;
        Node *left, *right;

        Node(char d, int f, int idx) {
            data = d;
            freq = f;
            index = idx;
            left = right = nullptr;
        }
    };

    struct Compare {
        bool operator()(Node* a, Node* b) {
            if (a->freq != b->freq)
                return a->freq > b->freq;
            return a->index > b->index;
        }
    };

    void preorder(Node* root, string code, vector<string>& ans) {
        if (!root) return;

        if (!root->left && !root->right) {
            ans.push_back(code.empty() ? "0" : code);
            return;
        }

        preorder(root->left, code + "0", ans);
        preorder(root->right, code + "1", ans);
    }

public:
    vector<string> huffmanCodes(string &s, vector<int> f) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            pq.push(new Node(s[i], f[i], i));
        }

        int nextIndex = n;
        while (pq.size() > 1) {
            Node* leftChild = pq.top();
            pq.pop();

            Node* rightChild = pq.top();
            pq.pop();

            int minIdx = min(leftChild->index, rightChild->index);
            Node* parent = new Node('$', leftChild->freq + rightChild->freq, minIdx);
            parent->left = leftChild;
            parent->right = rightChild;

            pq.push(parent);
        }

        vector<string> ans;
        if (!pq.empty()) {
            preorder(pq.top(), "", ans);
        }

        return ans;
    }
};