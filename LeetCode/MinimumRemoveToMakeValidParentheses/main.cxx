#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for (int i = 0 ;i < s.size();i++){
            if (s[i] == '('){
                st.push(make_pair('(',i));
            }else if (s[i] == ')'){
                if (st.empty()){
                    st.push(make_pair(')',i));
                }else{
                    if (st.top().first == '('){
                        st.pop();
                    }else{
                        st.push(make_pair(')',i));
                    }
                }
            }
        }
        unordered_map<int,bool> mm;
        while(!st.empty()){
            mm[st.top().second]=true;
            st.pop();
        }
        string ret;
        for (int i = 0 ; i < s.size();i++){
            if (mm[i]) continue;
            ret.push_back(s[i]);
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


