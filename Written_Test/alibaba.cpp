//////在某射击场有N个靶，每个靶上都有一个分数，存在score数组中，击中第i个靶的得分为score[left]*score[i]*score[right]，同时原left和right两个靶变为相
//////邻的靶，其中得分为0的靶是不能射击的，当left不存在或者不能射击时，得分为score[i]*score[right],同理，right也遵循此规则，当left和right都不存在或者
//////都不能射击时，得分为score[i]，请计算出击中所有能射击的靶，最多得多少分？
////
//////输入样例 :4 2 3 0 3
////
//////输出结果:12
////
////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <numeric>
////using namespace std;
//////#define debug_
////
////int func(vector<int>& nums) {
////    int N = nums.size();
////    nums.insert(nums.begin(), 1);
////    nums.insert(nums.end(), 1);
////
////    vector<vector<int> > rangeValues(nums.size(), vector<int>(nums.size(), 0));
////
////    for (int len = 1; len <= N; ++len) {
////        for (int start = 1; start <= N - len + 1; ++start) {
////            int end = start + len - 1;
////            int bestCoins = 0;
////            for (int final = start; final <= end; ++final) {
////                int coins = rangeValues[start][final - 1] + rangeValues[final + 1][end];
////                coins += nums[start - 1] * nums[final] * nums[end + 1];
////                if (coins > bestCoins) bestCoins = coins;
////            }
////            rangeValues[start][end] = bestCoins;
////        }
////    }
////    return rangeValues[1][N];
////}
////
////int main()
////{
////    int n(0);
////#ifdef debug_
////
////#else
////    cin >> n;
////    int k;
////    long long sum(0);
////    vector<int> vec;
////    for (int i = 0; i < n;++i)
////    {
////        cin >> k;
////        if (k == 0)
////        {
////            sum += func(vec);
////            vec.clear();
////        }
////        else
////        {
////            vec.push_back(k);
////        }
////    }
////#endif
////    sum += func(vec);
////
////    cout << sum;
////    return 0;
////}
//
//
//
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//    int t; cin >> t;
//    for(int i = 0; i < t; i++) {
//    	int n; cin >> n;
//        vector<int> a;
//        for(int j = 0; j < 2*n; j++) {
//            int tmp; cin >> tmp;
//        	a.push_back(tmp);
//        }
//        sort(a.begin(), a.end());
//        int odd = 0;
//        int count = 0;
//        for (int i = 0; i < 2*n-1; i++) {
//        	if (a[i] == a[i+1]) {
//            	count++;
//            } else {
//            	count++;
//                if (count % 2 != 0) {
//                	odd++;
//                }
//                count = 0;
//            }
//        }
//        if (count % 2 != 0)
//        	odd++;
//        if (odd > 2)
//            cout << "NO";
//        else
//            cout << "YES";
//    }
//
//    return 0;
//}

#include <iostream>
using namespace std;

long long int f(int m) {
    if(m > 0)
        return f(m-1)+f(m-2);
}

int main()
{
    cout << f(39) << endl;
    return 0;
}