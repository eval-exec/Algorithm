#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Single-Threaded CPU

*/

class Solution {
  public:
    struct my_comparator {
        bool operator()(const vector<int> &a, const vector<int> &b) const {
            if (a[1] > b[1]) return true;
            if (a[1] == b[1]) return a[2] > b[2];
            return false;
        }
    };
    vector<int> getOrder(vector<vector<int>> &tasks) {

        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end(), [](const vector<int> &v1, const vector<int> &v2) -> bool {
            return v1[0] < v2[0];
        });

        priority_queue<vector<int>, vector<vector<int>>, my_comparator> pq;
        vector<int> rets;
        long now = 0;
        int ti = 0;

        while (rets.size() < tasks.size()) {
            if (pq.empty() && ti < tasks.size()) {
                if (tasks[ti][0] > now) now = tasks[ti][0];
            }
            while (ti < tasks.size() && tasks[ti][0] <= now) {
                pq.push(tasks[ti]);
                ti++;
            }
            if (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                now += top[1];
                rets.push_back(top[2]);
            }
        }
        return rets;
    }
};

//// END
struct T {
    vector<vector<int>> tasks;

};

TEST(Solution, test) {
    T ts[] = {
        {
            .tasks={
                {142, 185}, {142, 74}, {669, 253}, {669, 953}, {669, 694}, {669, 474}, {669, 839}, {457, 87},
                {457, 371}, {457, 510}, {457, 691}, {457, 237}, {457, 225}, {457, 413}, {457, 935}, {457, 703},
                {669, 709}, {669, 687}, {669, 911}, {669, 741}, {669, 526}, {669, 900}, {669, 842},
                {287, 709}, {107, 420}, {107, 277}, {107, 119}, {107, 28}, {894, 373}, {894, 592}, {894, 698},
                {894, 947}, {894, 120}, {894, 296}, {894, 429}, {894, 792}, {894, 677}, {13, 6}, {13, 551},
                {366, 76}, {366, 385}, {366, 437}, {366, 72}, {366, 518}, {366, 7}, {366, 454}, {366, 382},
                {128, 796}, {128, 582}, {128, 978}, {128, 255}}
        },

    };

    for (T t : ts) {
        Solution solution;
        for (auto n : solution.getOrder(t.tasks)) {
        }
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


