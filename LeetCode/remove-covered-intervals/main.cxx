#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0, left = -1, right = -1;

        for (vector<int> &it:intervals) {
            if (it[0] > left && it[1] > right) {
                left = it[0];
                count++;
            }
            right = max(right, it[1]);
        }

        return count;
    }

};

int main() {
    Solution solution;
    vector<vector<int>> input = {{1, 2},
                                 {1, 4},
                                 {3, 4}};
    int ret = solution.removeCoveredIntervals(input);
    cout << ret << endl;
    cout << "end"<< endl;

    return 0;
}