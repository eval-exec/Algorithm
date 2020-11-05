#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rets;
        int i = 1;
        while (i <= n) {
            rets.push_back(conv(i));
            i++;
        }
        return rets;

    }

private:
    string Fizz = "Fizz";
    string Buzz = "Buzz";
    string FizzBuzzs = Fizz + Buzz;

    string conv(int number) {
        if (number % 3 == 0) {
            if (number % 5 == 0) {
                return FizzBuzzs;
            }
            return Fizz;

        } else if (number % 5 == 0) {
            return Buzz;
        }
        return to_string(number);

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


