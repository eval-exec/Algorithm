#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

//// START ## Minimum Number of Operations to Make String Sorted
class Solution {
  public:
    int makeStringSorted(string s) {
        sorted.replace(s)
        sort(sorted.begin(), sorted.end());
        int i = s.size() - 1;
        for (; i >= 1; i--) {
            if (s[i] < s[i - 1]) break;
        }
        int j = i;
        while (s[j] < s[i - 1]) {
            j++;
        }
        j--;
        swap(s[i-1],s[j]);
        reverse(s.begin()+i,s.end());



    }
  private:
    string sorted;
    unordered_map<,unordered_map<int, int>> memo;
    int mod = 1e9 + 7;

};

//// END




struct T {

};

TEST(Solution, test) {
    T ts[] = {
        {

        },
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


