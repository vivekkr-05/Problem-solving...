// Nth Root of M

// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.


class Solution {
	public:
	int nthRoot(int n, int m) {
	    if (n>0 && m==1) return 1;
	    if(n>0 && m==0) return 0;
		if (n == 0)
			return - 1;
		int low = 1; int high = m;
		while (low <= high) {
			int mid = (low + high)/2;
			int value = power_function(mid, n, m);
			if (value == m) {
				return mid;
			} else if (value <m) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return - 1;
	}
	
	int power_function(int base, int power, int limit) {
		int result = 1;
		for (int i = 0; i<power; i++) {
			result = result*base;
			if (result>limit)
				return result;
		}
		return result;
	}
	
};
