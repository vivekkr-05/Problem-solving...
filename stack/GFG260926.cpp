// Next Greater Element


// You are given an array arr[] of integers, the task is to find the next greater for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1.


class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                res[i] = s.top();
            }
            s.push(arr[i]);
        }
        return res;
    }
};