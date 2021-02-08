#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string> &emails) {
        set<string> ss;
        for (string &email: emails) {
            string result;
            bool domain = false;
            bool ignore = false;
            for (char c : email) {
                if (!domain) {
                    if (c == '@') {
                        domain = true;
                        continue;
                    }

                    if (ignore) {
                        continue;
                    }
                    if (c == '+') {
                        ignore = true;
                        continue;
                    }

                    if (c != '.') {
                        result += c;
                        continue;
                    }
                } else {
                    result += c;

                }
            }
            ss.insert(result);
        }
        return ss.size();
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


