#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        init(bank);
        int step  = 0;
        queue<string> qq;
        qq.push(start);
        unordered_map<string,bool> visited;
        visited[start] = true;
        while(!qq.empty()){
            int qlen = qq.size();
            while(qlen > 0){
                string now  = qq.front();
                if (now == end) return step;
                qq.pop();
                for (int i = 0 ; i < now.size() ;i++){
                    string tmp = now;
                    tmp[i] = '*';
                    auto f = mm.find(tmp);
                    if (f == mm.end()) continue;
                    for (auto nx: f->second){
                        if (visited[nx]) continue;
                        visited[nx]=true;
                        qq.push(nx);
                    }
                }
                qlen--;
            }
            step++;
        }
        return -1;
    }
private:
    unordered_map<string,vector<string>> mm;
    void init(const vector<string> & bank){
        for (const string & gen : bank){
            for (int i = 0 ;i < gen.size();i++){
                string tmp = gen;
                tmp[i] = '*';
                mm[tmp].push_back(gen);
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


