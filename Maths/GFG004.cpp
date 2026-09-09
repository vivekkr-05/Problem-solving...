// Given three integers a, d and n.
// Where a is the first term, d is the common difference of an A.P.  Calculate the nth term of A.P. 
// The nth term is given by an = a + (n-1)d

#include <iostream>
using namespace std;

int main() {
    int a, d, n;
    cin >> a >> d >> n;

    int nth= a+(n-1)*d;
    cout<<nth;

    return 0;
}
