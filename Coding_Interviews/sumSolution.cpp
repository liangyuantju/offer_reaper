//求1+2+3+...+n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
#include <iostream>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }


    int Add(int num1, int num2)
    {
         while (num2!=0) {
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
         }
         return num1;
    }

};

int main()
{
    Solution test;
    cout<<test.Sum_Solution(3)<<endl;
    cout<<test.Add(2,3);
    return 0;
}