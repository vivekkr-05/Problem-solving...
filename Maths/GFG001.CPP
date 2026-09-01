// Given the first 2 terms a and b of a Geometric Series. The task is to find the nth term of the series.


// It's solution by using loop:-


class Solution {
  public:
    int termOfGP(int a, int b, int n) {
        int ratio= b/a;
        int nth=1;
        for(int i=1; i<n; i++){
            nth=nth*ratio;
        }
        nth=nth*a;
        return nth;
    }
};