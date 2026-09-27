// Triplet Sum in Array

// Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.
// Return true if such a triplet exists, otherwise, return false.


class Solution {
public:
    bool hasTripletSum(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int current_sum = arr[i] + arr[left] + arr[right];
                if (current_sum == target) {
                    return true;
                } else if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return false;
    }
};