#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


class Solution {
    public:
        bool isRobotBounded(string instructions) {
            pair<int,int> init  = make_pair(0,0);
            int di = 0;
            for (char c : instructions){
                move(c,di,init);
            }
            for (char c : instructions){
                move(c,di,init);
            }
            int dist_2 = pow(init.first,2) + pow(init.second,2);
            if (dist_2 == 0 ) return true;

            for (char c : instructions){
                move(c,di,init);
            }
            for (char c : instructions){
                move(c,di,init);
            }
            int dist_4 = pow(init.first,2) + pow(init.second,2);
            return dist_4 < dist_2 * 2;
        }
    private:
        void move(char c,int &di, pair<int,int> init){
            if (c == 'L'){
                di--;
                if (di < 0){
                    di += 4;
                }
            }else if (c == 'R'){
                di++;
                if (di == 4){
                    di = 0;
                }
            }else {
                if (di == 0){
                    init.second++;
                }else if (di == 1){
                    init.first++;
                }else if (di == 2){
                    init.second--;
                }else {
                    init.first--;
                }
            }
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


