#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> ret;
        bool comment=false;
        string cur;
        for (string str: source) {
            for (int i = 0; i < str.size(); i++) {
                if (comment) {
                    if (str[i] == '*' && i <= str.size() - 2) {
                        if (str[i + 1] == '/') {
                            i++;
                            comment = false;
                            continue;
                        }
                    }
                } else {
                    if (str[i] == '/' && i <= str.size() - 2) {
                        if (str[i + 1] == '/') {
                            break;
                        }
                        if (str[i + 1] == '*') {
                            i++;
                            comment = true;
                        }
                    }
                }

                if (!comment) {
                    cur.push_back(str[i]);
                }
            }
            if (!comment) {
                if (!cur.empty()) {
                    ret.push_back(cur);
                    cur.erase(cur.begin(), cur.end());
                }
            }
        }
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


