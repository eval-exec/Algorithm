#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int len = source.size();
        unordered_map<int, unordered_set<int>> mm;
        for (const auto &swap : allowedSwaps) {
            mm[swap[0]].insert(swap[1]);
            mm[swap[1]].insert(swap[0]);
        }
        vector<vector<int>> groups;
        unordered_map<int, int> visited;
        for (int i = 0; i < len; i++) {
            visited[i] = -1;
        }

        for (int i = 0; i < len; i++) {
            if (visited.find(i) == visited.end())continue;
            queue<int> qq;
            vector<int> group;
            qq.push(i);
            visited.erase(i);
            while (!qq.empty()) {
                int n = qq.size();
                int now = qq.front();
                group.push_back(now);
                qq.pop();
                while (n > 0) {
                    for (auto x: mm[now]) {
                        if (visited.find(x) == visited.end()) continue;
                        visited.erase(x);
                        qq.push(x);
                    }
                    n--;
                }
            }
            groups.push_back(group);
        }

        int diffs = 0;
        for (const auto &group:groups) {
            diffs += count_diff(source, target, group);
        }
        for (const auto &x : visited) {
            if (source[x.first] != target[x.first]) diffs++;
        }
        return diffs;
    }
  private:
    int count_diff(const vector<int> &source, const vector<int> &target, const vector<int> &group) {
        unordered_map<int, int> mm_s;
        for (const int &i : group) {
            mm_s[source[i]]++;
        }
        int diff = 0;
        for (const int &i : group) {
            int n = mm_s[target[i]];
            if (n == 0) {
                diff++;
                continue;
            }
            mm_s[target[i]]--;
        }
        return diff;
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


