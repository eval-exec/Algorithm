
#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
    int fib(int N) {
        auto r = mm.find(N);
        if (r != mm.end()){
            return r->second;
        }
        if (N <= 1){
            mm[N] = N;
            return N;
        }
        int sum = fib(N-1) + fib(N-2);
        mm[N] = sum;
        return sum;
        
    }
    private:
map<int,int> mm;
};

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2){
            mm[n] = n;
            return n;
        }
        
        auto x = mm.find(n);
        if (x!= mm.end()){
            return x->second;
        }

        int ans = climbStairs(n-1) + climbStairs(n-2);
        mm[n] = ans;
        return ans;
	}
private:
	map<int,int> mm;
};
int main() {
	testing::InitGoogleTest();

	return RUN_ALL_TESTS();
}


