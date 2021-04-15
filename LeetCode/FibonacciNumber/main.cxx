#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
	if (n <= 1) return n;
	auto f = memo.find(n);
	if (f != memo.end()) return f.second;
	int ret = fib(n-1) + fib(n-2);
	memo[n] = ret;
	return ret;
    }
private:
    unordered_map<int,int> memo;
};





struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },
        {

        },

    };


    for (T t : ts){
        Solution solution;

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


