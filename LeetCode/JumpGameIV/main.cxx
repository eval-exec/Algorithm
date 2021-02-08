#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int> &arr) {
        unordered_map<int, vector<int>> vi;
        for (int i = 0; i < arr.size(); i++) {
            vi[arr[i]].push_back(i);
        }
        unordered_map<int, bool> visited;
        queue<int> qq;

        int dis = 0;

        const int start = 0;
        const int end = arr.size() - 1;
        qq.push(start);
        visited[start] = true;
        while (!qq.empty()) {
            int qn = qq.size();
            while (qn > 0) {
                int now = qq.front();
                qq.pop();
                if (now == end) return dis;

                if (now + 1 < arr.size() && !visited[now + 1]) {
                    visited[now + 1] = true;
                    qq.push(now + 1);
                }
                if (now - 1 >= 0 && !visited[now - 1]) {
                    visited[now - 1] = true;
                    qq.push(now - 1);
                }
                const auto &f = vi.find(arr[now]);
                if (f != vi.end()) {
                    for (const int &ni : f->second) {
                        if (visited[ni]) continue;
                        visited[ni] = true;
                        qq.push(ni);
                    }
                    vi.erase(arr[now]);
                }
                qn--;
            }
            dis++;
        }
        return -1;
    }
};

struct T {
    vector<int> arr;
    int expect;

};

//TEST(Solution, test) {
//    T ts[] = {
//        {
//            1
//        },
//
//    };
//
//    for (T t : ts) {
//        Solution solution;
//        EXPECT_EQ(solution.minJumps(t.arr), t.expect);
//    }
//}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


