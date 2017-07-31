#include<iostream>
using namespace std;

int plus_ly(int m, int n){
    int sum, carry;
    do{
        sum = m ^ n;
        carry = (m & n) << 1;

        m = sum;
        n = carry;
    } while (carry != 0);

    return sum;
}

int main()
{
    int m = 2, n = 9;
    cin>>m>>n;
    int res = plus_ly(m, n);
    cout << res << endl;
    return 0;
}