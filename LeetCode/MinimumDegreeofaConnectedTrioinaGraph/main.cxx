#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> neis(n+1);
        vector<vector<bool>> cons(n+1,vector<bool>(n+1));
        for (const auto & edge : edges){
            if (edge[0] < edge[1]){
                cons[edge[0]][edge[1]] = true;
            }else{
                cons[edge[1]][edge[0]] = true;
            }
            neis[edge[0]]++;
            neis[edge[1]]++;
        }
        int ret = INT_MAX;
        for (int f = 1; f <= n; f++) {
            for (int s = f+1; s <= n; s++) {
                if (!cons[f][s]) continue;
                for (int t = s+1; t <= n; t++) {
                    if (!cons[s][t] || !cons[f][t]) continue;
                    ret = min(ret,neis[f] + neis[s]+ neis[t] - 6);
                }
            }
        }
        return ret == INT_MAX? -1:ret;
    }
};
class Solution {
  private:
    unordered_map<int, int> mm;
    int hash(int f, int s, int t) {
        if (f > t) {
            swap(f, t);
        }
        if (s > t) {
            swap(s, t);
        }
        if (f > s) {
            swap(f, s);
        }
        return f * 401 * 401 + s * 401 + t;
    }
  public:
    int minTrioDegree(int n, vector<vector<int>> &edges) {
        vector<vector<bool>> cons(n + 1, vector<bool>(n + 1));
        for (const auto &edge: edges) {
            if (edge[0] < edge[1]){
                cons[edge[0]][edge[1]] = true;
            }else{
                cons[edge[1]][edge[0]] = true;
            }
            mm[edge[0]]++;
            mm[edge[1]]++;
        }
        int MinDegree = INT_MAX;
        unordered_map<int, array<int, 3>> trios;
        if (trios.empty()) return -1;
        cout << trios.size() << endl;

        for (const auto &trio : trios) {
            MinDegree = min(MinDegree,
                            int(mm[trio.second[0]] +
                                mm[trio.second[1]] +
                                mm[trio.second[2]] -
                                6));
        }

        return MinDegree;
    }
};

struct T {
    int n;
    vector<vector<int>> nums;
};

TEST(Solution, test) {
    T ts[] = {
        {
            6,
            {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}},
        },
{
400,

},
    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.minTrioDegree(t.n, t.nums), 3);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

