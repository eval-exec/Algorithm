#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class Solution {
  public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        iscomemo.resize(51, vector<bool>(51));
        for (int i = 1; i <= 50; i++) {
            for (int j = i; j <= 50; j++) {
                bool r = __gcd(i, j) == 1;
                iscomemo[i][j] = r;
                iscomemo[j][i] = r;
            }
        }

        vector<int> ret(nums.size());
        for (const auto &edge:edges) {
            cons[edge[0]].push_back(edge[1]);
            cons[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(nums.size());
        visited[0] = true;
        unordered_map<int, pair<int, int>> ancestors; // value,<index, depth>;
        dfs(ret, nums, visited, ancestors, 0, 1);
        return ret;
    }
  private:
    unordered_map<int, vector<int>> cons;
    vector<vector<bool>> iscomemo;
    void dfs(vector<int> &ret,
             const vector<int> &nums,
             vector<bool> &visited,
             unordered_map<int, pair<int, int>> &ancestor,
             const int &node_idx,
             int depth) {

        if (node_idx >= ret.size()) return;
        ret[node_idx] = -1;
        int d = 0;
        for (const auto &ans : ancestor) {
            if (iscomemo[ans.first][nums[node_idx]]) {
                if (ans.second.second > d) {
                    d = ans.second.second;
                    ret[node_idx] = ans.second.first;
                }
            }
        }

        bool noexist = ancestor.find(nums[node_idx]) == ancestor.end();
        auto prev = ancestor[nums[node_idx]];
        ancestor[nums[node_idx]] = make_pair(node_idx, depth);
        for (auto child_idx: cons[node_idx]) {
            if (visited[child_idx]) continue;
            visited[child_idx] = true;
            dfs(ret, nums, visited, ancestor, child_idx, depth + 1);

            visited[child_idx] = false;
        }
        if (noexist) {
            ancestor.erase(nums[node_idx]);
        } else {
            ancestor[nums[node_idx]] = prev;
        }
    }
};

struct T {
    vector<int> nums;
    vector<vector<int>> edges;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .nums={2, 3, 3, 2},
            .edges={{0, 1}, {1, 2}, {1, 3}},
        },
        {
            .nums={5, 6, 10, 2, 3, 6, 15},
            .edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}}
        },
        {
            .nums={9, 16, 30, 23, 33, 35, 9, 47, 39, 46, 16, 38, 5, 49, 21, 44, 17, 1, 6, 37, 49, 15, 23, 46, 38, 9, 27,
                   3, 24, 1, 14, 17, 12, 23, 43, 38, 12, 4, 8, 17, 11, 18, 26, 22, 49, 14, 9},
            .edges={{17, 0}, {30, 17}, {41, 30}, {10, 30}, {13, 10}, {7, 13}, {6, 7}, {45, 10}, {2, 10}, {14, 2},
                    {40, 14}, {28, 40}, {29, 40}, {8, 29}, {15, 29}, {26, 15}, {23, 40}, {19, 23}, {34, 19}, {18, 23},
                    {42, 18}, {5, 42}, {32, 5}, {16, 32}, {35, 14}, {25, 35}, {43, 25}, {3, 43}, {36, 25}, {38, 36},
                    {27, 38}, {24, 36}, {31, 24}, {11, 31}, {39, 24}, {12, 39}, {20, 12}, {22, 12}, {21, 39}, {1, 21},
                    {33, 1}, {37, 1}, {44, 37}, {9, 44}, {46, 2}, {4, 46}}
        }

    };

    for (T t : ts) {
        Solution solution;
        auto rr = solution.getCoprimes(t.nums, t.edges);
        for (int r : rr) {
            printf("%d ", r);
        }
        cout << endl;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


