#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
    public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        visited.resize(bikes.size());
        return cal(workers,0,bikes);
    }
    private:
    unordered_map<int,int> memo;
    vector<bool> visited;
    long gen(int wi,const vector<bool> &visited){
        bitset<10> bs;
        
        for (int i =0;i < visited.size();i++){
            bs.set(i,visited[i]);
        }
        return wi+bs.to_ulong()*100;
    }

    int cal(const vector<vector<int>> &workers,int wi,const vector<vector<int>> &bikes){
        if (wi == workers.size()) return 0;
        {
            auto f = memo.find(gen(wi,visited));
            if (f != memo.end()) return f->second;
        }
        int lenx = INT_MAX;
        for (int b = 0;b < bikes.size();b++){
            if (visited[b]) continue;
            visited[b]=true;
            lenx = min(lenx, abs(workers[wi][0]-bikes[b][0])+abs(workers[wi][1]-bikes[b][1])+cal(workers,wi+1,bikes));
            visited[b]=false;
        }
        memo[gen(wi,visited)] = lenx;
        return lenx;
    }

};





struct T{

};

TEST(Solution,test){
    T ts[] = {
        {

        },

    };

    Solution solution;

    for (T t : ts){

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


