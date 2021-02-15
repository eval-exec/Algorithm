#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
  public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        for (int i = 0; i < pid.size(); i++) {
            pc[ppid[i]].insert(pid[i]);
        }
        vector<int> kill_list;
        exec_kill(kill, kill_list);
        return kill_list;
    }
  private:
    unordered_map<int, unordered_set<int>> pc;
    void exec_kill(int pid, vector<int> &kill_list) {
        auto f = pc.find(pid);
        if (f != pc.end()) {
            for (int c : f->second) {
                exec_kill(c, kill_list);
            }
        }
        kill_list.push_back(pid);
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


