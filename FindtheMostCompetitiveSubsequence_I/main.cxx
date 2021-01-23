#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        for (int i = 0;i < nums.size();i++){
            if (st.empty()){
                st.push(nums[i]);
            }else{
                int n = nums.size() - i;
                while(st.size() + n > k){
                    if (st.empty()) break;
                    if (st.top() > nums[i]){
                        st.pop();
                    }else{
                        break;
                    }
                }
                if (st.size() < k){
                    st.push(nums[i]);
                }
            }
        }
        vector<int> ret(k);
        int i = k-1;
        while(!st.empty()){
            ret[i] = st.top();
            st.pop();
            i--;
        }
        return ret;
    }
};


struct T{

};

TEST(Solution,test){
    T ts[] = {
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


