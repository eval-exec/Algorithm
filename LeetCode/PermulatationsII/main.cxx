#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/*
 * Given a collection of numbers, nums,
 * that might contain duplicates,
 * return all possible unique permutations in any order.


 */


void print(vector<int> &ns) {
    for (int n: ns) {
        cout << n << " ";
    }
    cout << endl;
}

void prints(vector<vector<int>> nss) {
    for (auto &ns: nss) {
        print(ns);
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        len = nums.size();
        if (len == 0) {
            return {};
        }
        map<int, int> mm;
        for (auto n : nums) {
            mm[n] += 1;
        }
        vector<vector<int>> rets;
        backtrack({}, mm, rets);
        return rets;
    }

private:
    int len = 0;

    void backtrack(vector<int> comb, map<int, int> mm, vector<vector<int>> &rets) {
        if (comb.size() == len) {
            rets.push_back(comb);
            return;
        }
        for (auto m : mm) {
            if (m.second == 0) {
                continue;
            }
            comb.push_back(m.first);
            mm[m.first] -= 1;

            backtrack(comb, mm, rets);
            comb.pop_back();
            mm[m.first] += 1;
        }
    }
};

struct T {
    vector<int> nums;

};

TEST(Solution, test) {
    T ts[] = {
            {
                    {{1, 2, 3}},
            },

    };


    for (T t : ts) {
        Solution solution;
        auto gots = solution.permuteUnique(t.nums);
        prints(gots);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


