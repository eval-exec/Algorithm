#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        unordered_map<int,bool> visited;
        queue<int> qq;
        qq.push(0);
        visited[0]=true;
        while(!qq.empty()){
            int qlen = qq.size();
            while(qlen>0){
                qlen--;
                int now = qq.front();
                qq.pop();
                for (int n : rooms){
                    if (visited[n]) continue;
                    visited[n]=true;
                    qq.push(n);
                }
            }
        }
        return visited.size() == rooms.size();
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


