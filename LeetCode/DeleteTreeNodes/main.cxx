#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    int deleteTreeNodes(int nodes, vector<int> &parent, vector<int> &value) {
        for (int i = 0; i < parent.size(); i++) {
            mm[parent[i]].insert(i);
        }
        int count = 0;
        queue<int> nds;
        nds.push(0);

        while (!nds.empty()) {
            int n = nds.size();
            while (n > 0) {
                int idx = nds.front();
                nds.pop();
                if (sum(idx, value) != 0) {
                    count++;
                    for (int c :mm[idx]) {
                        nds.push(c);
                    }
                }
                n--;
            }
        }
        return count;
    }
  private:
    map<int, set<int>> mm;
    map<int, int> sum_memo;
    int sum(int node_index, const vector<int> &value) {
        {
            auto f = sum_memo.find(node_index);
            if (f != sum_memo.end()) return f->second;
        }
        int ret = value[node_index];

        {
            auto childs = mm.find(node_index);
            if (childs == mm.end()) return ret;
            for (int child : childs->second) {
                ret += sum(child, value);
            }
        }
        sum_memo[node_index] = ret;
        return ret;
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


