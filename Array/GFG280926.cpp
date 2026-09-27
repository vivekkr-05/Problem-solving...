// Minimize the Heights

// Given an array arr[] representing the heights of n towers and a positive integer k.
// For each tower, perform exactly one of the following operations exactly once:

// Increase its height by k, or
// Decrease its height by k.
// After performing the operation on every tower, the height of any tower must not become negative.

// Return the minimum possible difference between the heights of the tallest and the shortest towers after modifying all the towers.



class Solution {
public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int minVal = min(smallest, arr[i + 1] - k);
            int maxVal = max(largest, arr[i] + k);

            if (minVal < 0) continue;

            ans = min(ans, maxVal - minVal);
        }

        return ans;
    }
};