// Given an array arr[], the task is to find whether the arr is palindrome or not.  An array is said to be palindrome if its reverse array matches the original array.


class Solution {
  public:
    bool isPalindrome(vector<int> &arr) {
        int n=(1+arr.size())/2;
        int a=arr.size();
        for(int i=0; i<=n; i++){
            if(arr[i]!=arr[a-1])
            return false;
            a--;
        }
        return true;
    }
};
