#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        vector<bool> visited(arr.size());
        queue<int> qq;
        qq.push(start);
        while (!qq.empty()) {
            if (arr[start] == 0) return true;

            int now = qq.front();
            qq.pop();
            if (arr[now] == 0) return true;
            if (now >= arr[now]) {
                if (!visited[now - arr[now]]) {
                    qq.push(now - arr[now]);
                }
            }
            if (now + arr[now] <= arr.size() - 1) {
                if (!visited[now + arr[now]]) {
                    qq.push(now + arr[now]);
                }
            }
            visited[now] = true;
        }
        return false;
    }
};


struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


