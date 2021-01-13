#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            for (const int p : people){
                mm[p] += 1;
            }
            int boats = 0;
            while(!mm.empty()){
                int em = limit;
                int count = 0;
                while(em>0 && !mm.empty() && count < 2){
                    int p = 0;
                    if (pick(em,p)){
                        em -= p;
                        count++;
                    }else{
                        break;
                    }
                }
                if (count > 0) boats++;
            }
            return boats;
        }
    private:
        map<int,int> mm;
        bool pick(int limit, int &who){
            auto l = mm.lower_bound(limit);
            if (l == mm.begin() && l->first > limit) return false;
                who = l->first;
            if (l->first > limit){
                who = prev(l)->first;
            }
            if (l == mm.end()) {
                who = mm.rbegin()->first;
            }
            mm[who]--;
            if (mm[who] == 0){
                mm.erase(who);
            }
            return true;
        }
};





struct T{
    vector<int> people;
    int limit;
    int expect;

};

TEST(Solution,test){
    T ts[] = {
        {
            {{1,2}},
            3,
            1
        },
        {
            {{3,2,2,1}},
            3,
            3
        },
        {
            {{3,5,3,4}},
            5,
            4
        }


    };


    for (T t : ts){
        Solution solution;
        EXPECT_EQ(solution.numRescueBoats(t.people,t.limit),t.expect);
    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


