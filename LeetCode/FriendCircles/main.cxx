#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int findCircleNum(vector<vector<int>> &M) {
        visited = vector<bool>(M.size());
        int count = 0;
        for (int i = 0; i < M.size(); i++) {
            if (!visited[i]) {
                dfs(M, i);
                count++;
            }
        }
        return count;
    }
  private:
    vector<bool> visited;
    void dfs(const vector<vector<int>> &M, int i) {
        visited[i] = true;
        for (int j = 0; j < M.size(); j++) {
            if (!visited[j] && M[i][j]) {
                dfs(M, j);
            }
        }
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


