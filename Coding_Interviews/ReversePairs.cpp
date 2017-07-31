#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data){
		int length = data.size();
        if(length <= 0)
            return 0;
        vector<int> copy(data);

        int count = InversePairsCore(data,copy,0,length - 1);

        return count;
    }

    int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end){
        int count=0;
        if(start == end){
            copy[start] = data[start];
            return 0;
        }

        int mid = (end + start) >> 1;
        int leftcount = InversePairsCore(copy, data, 0, mid);
        int rightcount = InversePairsCore(copy, data, mid+1, end);
        int cindex = end;
        int i = mid, j = end;
        while(i >= start && j > mid) {
             if(data[i]>data[j]) {
                count += (j-mid);
                copy[cindex--] = data[i--];
             } else {
                 copy[cindex--] = data[j--];
             }
        }

        while(i >= start) {
            copy[cindex--] = data[i--];
        }

        while(mid < j) {
            copy[cindex--] = data[j--];
        }

        return (count+leftcount+rightcount)%1000000007;
    }
};

int main()
{
    Solution test;
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    int res = test.InversePairs(vec);
    cout << res << endl;
    return 0;
}