#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        unordered_map<int, unordered_set<int>> mm;
        for (int ei = 0; ei < graph.size(); ei++) {
            for (int n : graph[ei]) {
                mm[ei].insert(n);
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            unordered_map<int, int> gp;
            if (gp.find(i) != gp.end()) continue;
            gp[i] = 0;

            queue<int> qq;
            qq.push(i);
            while (!qq.empty()) {
                int qlen = qq.size();
                while (qlen > 0) {
                    int now = qq.front();
                    qq.pop();
                    int now_gp = gp[now];
                    for (int nx : mm[now]) {
                        auto f = gp.find(nx);
                        if (f == gp.end()) {
                            gp[nx] = (now_gp + 1) % 2;
                            qq.push(nx);
                        } else {
                            if (f->second == now_gp) return false;
                        }
                    }
                    qlen--;
                }
            }
        }
        return true;
    }
};

struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },

    };

    for (T t : ts) {
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


