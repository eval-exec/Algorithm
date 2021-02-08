#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    string findReplaceString(string S,
                             vector<int> &indexes,
                             vector<string> &sources,
                             vector<string> &targets) {
        string ret = S;
        for (int i = 0; i < indexes.size(); i++) {
            const int index = indexes[i];
            const string &source = sources[i];
            const string &target = targets[i];
            if (!cmp(S, index, source)) continue;

            int d = getDelta(index);
            ret.erase(index + d, source.size());
            ret.insert(index + d, target);

            delta[index] = target.size() - source.size();
        }

        return ret;
    }

private:
    map<int, int> delta;

    int getDelta(int i) {
        int sum = 0;
        for (auto &d: delta) {
            if (d.first <= i) {
                sum += d.second;
            }
        }
        return sum;
    }

    bool cmp(const string &S, const int index, const string &src) {
        for (int i = 0; i < src.size(); i++) {
            if (S[index + i] != src[i]) {
                return false;
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

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


