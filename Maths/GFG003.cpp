// Given a number n, recursively sum the numbers from 1 to n and return the sum.

class Solution {
  public:
    int recursiveSum(int n) {
        if (n==0)
        return 0;
        
        return n+recursiveSum(n-1);
    }
};