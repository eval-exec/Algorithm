#include <iostream>
#include <vector>
#include <gtest/gtest.h>

/*
 * Input: date = "2019-01-09"

 */
class Solution {

public:
    int dayOfYear(std::string date) {
        std::vector<int> months({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});


        std::string year = date.substr(0, 4);
        std::string month = date.substr(5, 7);
        std::string day = date.substr(8, 10);
        int yy = std::stoi(year);
        int mm = std::stoi(month);
        int dd = std::stoi(day);

        if (leap(yy)) {
            months[1] = 29;
        }

        int sum = 0;
        for (int i = 1; i < mm; ++i) {
            sum += months[i - 1];
        }
        sum += dd;

        return sum;
    }

private:

    bool leap(int year) {

        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }
};

TEST(Solution, dayOfYear) {
    Solution solution;
    EXPECT_EQ(solution.dayOfYear("2019-01-09"), 9);
    EXPECT_NE(solution.dayOfYear("2019-01-09"), 10);
    EXPECT_EQ(solution.dayOfYear("2019-02-10"), 41);
    EXPECT_EQ(solution.dayOfYear("2003-03-01"), 60);
    EXPECT_EQ(solution.dayOfYear("2004-03-01"), 61);
}


int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}