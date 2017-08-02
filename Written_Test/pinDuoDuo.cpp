#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//第一题
//给定一个无序数组，包含正数，负数和０，要求从中找出３个数的乘积，
//使得乘积最大，要求时间复杂度：O(n),空间复杂度:O(1)
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}


void MaxCheng(int a[], int length) {
    int length;
    cin >> length;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    bool flag = true;
    if(length >= 3) {
        for (int i = 0; i < length; i++) {
            if(a[i] >= 0) {
                flag = false;
                break;
            }
        }

        if(flag) {
            for (int i = length-1; i >= length-3; i--) {
                for (int j = 0; j < i; j++) {
                    if (a[j] > a[j+1]) {
                        swap(a[j], a[j+1]);
                    }
                }
            }
            return a[length-3]*a[length-2]*a[length-1];
        }


        for (int i = 0; i < 2; i++) {
            for (int j = length-1; j > i; j--) {
                if (a[j] < a[j-1]) {
                    swap(a[j], a[j-1]);
                }
            }
        }
        for (int i = length-1; i >= length-3; i--) {
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                }
            }
        }
        long long max = ((a[0]*a[1]) >= (a[length-3]*a[length-2]))?(a[0]*a[1]):(a[length-3]*a[length-2]);
        cout << max*a[length-1] << endl;
    }
}

//第二题：［题目描述］
//有两个字符串表示的非常大非常大的大整数，算出他们的乘积，也是用字符串表示
//不能用系统自带的大整数类型.
//［输入描述：］
//空格分隔的两个字符串，代表输入的两个大整数
//［输出描述：］
//输入的乘积，用字符串表示
//todo C++_code
//todo Java_code


//第三题：［题目描述］
//假设一个探险家被困在了地低的迷宫之中，要从当前位置开始找到一条通往迷宫出口
//的路径.迷宫可以用一个二维矩阵组成,有的部分是墙,有的部分是路.迷宫之中有的路
//上还有门,每扇门都在迷宫的某个地方有与之匹配的钥匙,只有先拿到钥匙才能打开门.
//请设计一个人算法，帮助探险家找到脱困的最短路径.如前所述,迷宫是通过一个二维
//矩阵表示的,每个元素的值的含义如下０-墙,1-路,2-探险家的起始位置,3-迷宫的出口
//,大写字母-门,小写字母-对应大写字母所代表门的钥匙．
//［输入描述:］
//迷宫的地图，用二维矩阵表示.第一行是表示矩阵的行数和列数Ｍ和Ｎ
//后面的Ｍ行是矩阵的数据,每一行对应与矩阵的一行（中间没有空格）.M和N都不超过100,门不超过10扇
//［输出描述:］
//路径的长度，是一个整数
//［示例：］
//［输入：］
//5 5
//02111
//01a0A
//01003
//01001
//01111
//［输出：］
//7
//［说明：］
//输出7,对应的路径是(0,1)->(0,2)->(1,2)->(0,2)->(0,3)->(0,4)->(1,4)->(2,4)(无需输出)
//todo C++_code
//todo Java_code



//第四题：［题目描述］
//六一儿童节,老师带了很多好吃的巧克力到幼儿园.每块巧克力的重量为w[j],对于每个
//小朋友i,当他分到的巧克力大小达到h[i](即w[j]>h[i]),他才会上去表演节目.老师
//的目标是将巧克力分发给孩子们,使得最多的小孩上台表演.可以保证每个w[j]>0且不能
//将多块巧克力分给一个孩子或将一块分给多个孩子.
//［输入描述：］
//第一行：n, 表示h数组元素个数
//第二行：n个h数组元素
//第三行：m, 表示w数组元素个数
//第四行：m个w数组元素
//［输出描述：］
//上台表演学生人数
//todo: C++ code
void chocolateCore() {
    int n; cin >> n;
    vector<int> hv;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        hv.push_back(tmp);
    }
    int m; cin >> m;
    vector<int> wv;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        w.push_back(tmp);
    }
    sort(hv.begin(), hv.end());
    sort(wv.begin(), wv.end());
    int h = hv.size();
    int w = wv.size();
    int count = 0;
    int i = 0, j = 0;
    while(i < h && j < w) {
        if (wv[j] >= hv[i]) {
            i++;
            j++;
            count++;
        } else {
            j++;
        }
    }
    cout << count <<endl;
}





int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<MaxCheng(a, n)<<endl;
    return 0;
}