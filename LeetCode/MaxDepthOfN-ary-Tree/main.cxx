#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> qq;
        qq.push(root);
        int h = 0;
        while(!qq.empty()){
            h++;
            int n = qq.size();
            while(n > 0){
                Node* node = qq.front();
                qq.pop();
                for (auto c: node->children){
                    qq.push(c);
                }

                n--;
            }
        }
        return h;
        
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


