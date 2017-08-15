#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

//第一题：　求最长０１交叉子串长度
void first()
{
    string str;
    int length;
    while (cin >> str >> length) {
        //当字符串长度小于等于１时,　结果就是其长度
        if (length <= 1) {
            cout << length << endl;
            continue;
        }
        //当字符串长度大于１时,　需要对不同子串的长度进行对比


    }

}
//第一题


//第二题 逆序
//todo 算法复杂度过大
void second()
{
    int n;
    while (cin >> n) {
        vector<int> a;
        int temp;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(a[i]);
            if (res.size()%2 == 0) {
                int mid = res.size()/2;
                for (int i = 0; i < mid; i++) {
                    swap(res[i], res[res.size()-1-i]);
                }
            } else {
                int mid = res.size()/2;
                for (int i = 1; i <= mid; i++) {
                    swap(res[mid-i], res[mid+i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

}



//第三道 疯狂队列
void third()
{
    int n;
    while (cin >> n)
    {
        //输入
        vector<int> input;
        int high;
        for (int i = 0; i < n; i++) {
            cin >> high;
            input.push_back(high);
        }

        //当n < 3 时, 直接输出就可以
        if (n <= 1) {
            cout << "参数个数错误, 请重新输入!" << endl;
            continue;
        } else if (n < 3) {
            cout << "只有两个人   " << abs(input[1] - input[0]) << endl;
            continue;
        }

        //从小到大排序
        sort(input.begin(), input.end());
        vector<int>::iterator input_left = input.begin();
        vector<int>::iterator input_right = input.end() - 1;

        cout << "*************************************" << endl;

        cout << "input_left: " <<*input_left << endl;
        cout << "input_right: " <<*input_right << endl;

        cout << "*************************************" << endl;


        vector<int> res;
        res.push_back(*input_right--);
        //todo vector没有push_front()
        res.insert(res.begin(), *input_left++);
        res.push_back(*input_left++);

        cout << "input_left: " <<*input_left << endl;
        cout << "input_right: " <<*input_right << endl;

        cout << "*************************************" << endl;
        while (input_left <= input_right) {
            int left = *input_right - res.front();
            int right = *input_right - res.back();
            if (left > right) {
                //res.push_front(*input_right--);
                res.insert(res.begin(), *input_right--);
            } else {
                res.push_back(*input_right--);
            }
            if (input_left < input_right) {
                int left = *input_left - res.front();
                int right = *input_left - res.back();
                if (left > right) {
                    //res.push_front(*input_left++);
                    res.insert(res.begin(), *input_left++);
                } else {
                    res.push_back(*input_left++);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << endl;
        for(int i = 1; i < n; i++)
            sum += abs(res[i] - res[i-1]);
        cout << sum;
    }
}


int main()
{

    //second();
    third();
    return 0;
}