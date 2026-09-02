// Given a number n, check if the number is perfect or not. 
// A number is said to be perfect if sum of all its factors excluding the number itself is equal to the number.

class Solution {
public:
    bool isPerfect(int n) {
        if (n <= 1) return false;
        long long sum = 1; 
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum =sum+ i;
                if (i != n / i) {
                    sum =sum+ (n / i);
                }
            }
        }
        return sum == n;
    }
};