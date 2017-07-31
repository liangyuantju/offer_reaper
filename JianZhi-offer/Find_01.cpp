//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int j = 0;
        int i = row-1;
        for(; i >= 0 && j < col;){
            if(array[i][j] == target) {
               return true;
            }  else if (array[i][j] > target) { //这里一定是array[i][j]
                i--;
                continue;
            } else if(array[i][j] < target) {
                 j++;
                 continue;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int> > array(2);
    for (int i=0;i<2;i++) {
        array[i].resize(2);
    }
    array[0][0] = 1;
    array[0][1] = 2;
    array[1][0] = 3;
    array[1][1] = 4;
    Solution test;
    if(test.Find(4,array))
        cout<<"success!"<<endl;
    else
        cout<<"false!"<<endl;
    return 0;
}

