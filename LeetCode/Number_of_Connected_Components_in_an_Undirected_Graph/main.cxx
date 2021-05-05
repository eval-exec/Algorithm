#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Number of Connected Components in an Undirected Graph

*/

class Solution {
  public:
    int countComponents(int n, vector<vector<int>> &edges) {
        for (const auto &edge:edges) {
            cons[edge[0]].insert(edge[1]);
            cons[edge[1]].insert(edge[0]);
        }
        vector<bool> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])continue;
            count++;

            queue<int> qq;
            qq.push(i);
            visited[i] = true;
            while (!qq.empty()) {
                int qlen = qq.size();
                while (qlen > 0) {
                    qlen--;
                    int now = qq.front();
                    qq.pop();
                    for (auto c : cons[now]) {
                        if (visited[c]) continue;
                        visited[c] = true;
                        qq.push(c);
                    }
                }
            }
        }
        return count;
    }
  private:
    unordered_map<int, unordered_set<int>> cons;
};

//// END
struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
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


