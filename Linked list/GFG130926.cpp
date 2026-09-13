// Is Linked List Sorted
// Given the head of a singly linked list, find whether the given linked list is sorted or not.

// Note: The sorting can either be non-increasing or non-decreasing.
// Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool isSorted(Node* head) {
        if (!head || head->next == nullptr) {
            return true;
        }

        Node* temp = head;
        bool inc = false;
        bool dec = false;

        while (temp->next != nullptr) {
            if (temp->data < temp->next->data) {
                inc = true;
            } else if (temp->data > temp->next->data) {
                dec = true;
            }

            if (inc && dec) {
                return false;
            }

            temp = temp->next;
        }

        return true;
    }
};