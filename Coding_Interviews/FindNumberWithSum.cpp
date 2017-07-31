#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if((array.size() == 0) || (array.back()*2 < sum) || (array.front() > sum*2))
            return res;
        //找到中间数所在的位置
        vector<int>::iterator it1 = array.begin();
        while(it1 != array.end()) {
            if(*it1 > sum/2)
                break;
            it1++;
        }
        cout<<"中间位置数"<<*it1<<endl;
        //突然发现不必寻找中间数


        //寻找符合条件的数
        vector<int>::iterator it2 = array.begin();
        vector<int>::iterator it3 = array.end() - 1;
        int temp = 100000;
        while(it2 < it1 && it3 >= it1) {
            if (*it2 + *it3 == sum) {
                cout<<"满足条件的数字: "<<*it2 << " " << *it3<<endl;
                cout<<"满足条件的乘积: "<<(*it2 * *it3)<<endl;
                if (*it2 * *it3 < temp) {
                    temp = *it2 * *it3;
                    if(0 != res.size()) {
                        res.erase(res.begin(), res.end());
                    }
                    res.push_back(*it2);
                    res.push_back(*it3);
                }
                *it2++;
                *it3--;
            } else if (*it2 + *it3 < sum) {
                it2++;
            } else if(*it2 + *it3 > sum) {
                it3--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    Solution test;
    vector<int> res;
    res = test.FindNumbersWithSum(array, 7);
    cout<<"res.size() = "<<res.size()<<endl;
    if (0 != res.size()) {
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << " ";
        }
    }
    return 0;
}