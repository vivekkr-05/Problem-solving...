// Peak element


// Given an array arr[] where no two adjacent elements are same.
// Find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist).
// If there are multiple peak elements.
// Return index of any one of them.
// The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".
// Note: Consider the element before the first element and the element after the last element to be negative infinity.



class Solution {
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            }
            if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};