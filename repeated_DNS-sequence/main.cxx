
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


/*
 * All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T',
 * for example: "ACGAATTCCG". When studying DNA,
 * it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings)
 that occur more than once in a DNA molecule.



0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.

 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) {
            return {};
        }
        unordered_map<string, int> cm;
        for (int i = 0; i <= s.size() - 10; i++) {
            cm[s.substr(i, 10)]++;
        }

        vector<string> ret;
        for (pair<string, int> key : cm) {
            if (key.second >= 2) {
                ret.push_back(key.first);
            }

        }
        return ret;
    }

};

struct T {
    string DNA;
    vector<string> results;
};

void print(vector<string> vs) {
    for (string v: vs) {
        cout << v << " ";
    }
    cout << endl;
}

TEST(Solution, findRepeatedDnaSequences) {
    T ts[] = {
            {
                    "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
                    {"AAAAACCCCC", "CCCCCAAAAA"}
            },
            {
                    "AAAAAAAAAAAAA",
                    {
                     "AAAAAAAAAA",
                    }
            },
            {
                    "AAAAAAAAAAA",
                    {
                     "AAAAAAAAAA",
                    }
            }
    };

    Solution solution;
    for (T t: ts) {
        vector<string> results = solution.findRepeatedDnaSequences(t.DNA);

        set<string> s1(results.begin(), results.end());
        set<string> s2(t.results.begin(), t.results.end());
        ASSERT_EQ(s1, s2);
    }

}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


