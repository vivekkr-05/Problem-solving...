// Sum of Subarrays

// Given an array arr[], find the sum of all the subarrays of the given array.
#include <vector>

class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int count = (int)(i + 1) * (n - i);
            totalSum += arr[i] * count;
        }
        return totalSum;
    }
};