#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
/*
 *
 *We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.
Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        set<int> st;
        int global = 0,local = 0;
        int len = A.size();
        st.insert(A[len-1]);
        for (int i = len-2 ; i >=0;i--){
            if (A[i+1] < A[i]) local++;
            auto l =st.lower_bound(A[i]);

            global+=distance(st.begin(),st.lower_bound(A[i]));
            st.insert(A[i]);
        }
        return global == local;
    }
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


