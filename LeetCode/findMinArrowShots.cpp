#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int> >& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1, end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first <= end) {
                end = min(end, points[i].second);
            } else {
                ++res;
                end = points[i].second;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > points;
    pair<int, int> p1(10,16);
    pair<int, int> p2(2,8);
    pair<int, int> p3(1,6);
    pair<int, int> p4(7,12);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    int res = s.findMinArrowShots(points);
    cout << res << endl;
    return 0;
}