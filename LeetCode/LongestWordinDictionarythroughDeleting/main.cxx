#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        for (char c : s){
            sm[c]++;
        }
        int ri=-1;
        for (int i = 0 ;i < d.size();i++){
            if (ok(s,d[i])){
                if (ri == -1){
                    ri = i;
                }else if (d[i].size() > d[ri]){
                    ri = i;
                }else if (d[ri].size() == d[i].size(0)){
                    if (d[i] < d[ri]) ri = i;
                }
            }
        }
        return ri == -1? "": d[ri];
    }
private:
    unordered_map<char,int> sm;
    bool ok(const string &s,const string &t){
        int si = 0;
        int inc = 0;
        for (int i = 0;i < t.size();){
            if (si == s.size()) return false;
            if (i == t.size()) return true;
            if (s[si] == t[i]){
                i++;
            }
            si++;
        }
        return true; 
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


