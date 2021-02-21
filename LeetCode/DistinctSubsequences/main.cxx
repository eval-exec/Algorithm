#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
class Solution {
  public:
    int numDistinct(string s, string t) {
        if (t.empty()) return 1;
        if (s.empty()) return 0;

        {
            unordered_map<char, int> sm;
            for (char c : s) {
                sm[c]++;
            }
            unordered_map<char, int> tm;
            for (char c : t) {
                tm[c]++;
            }
            for (auto m : tm) {
                if (sm[m.first] < m.second) return 0;
            }
        }

        vector<vector<long>> dp(s.size(), vector<long>(t.size()));// [s][t]
        dp[0][0] = s[0] == t[0] ? 1 : 0;

        for (int i = 1; i < s.size(); i++) {
            dp[i][0] = s[i] == t[0] ? dp[i - 1][0] + 1 : dp[i - 1][0];
        }
        for (int it = 1; it < t.size(); it++) {
            if (s[it] == t[it]) dp[it][it] = dp[it - 1][it - 1];
            for (int is = it + 1; is < s.size(); is++) {
                dp[is][it] = dp[is - 1][it];
                if (s[is] == t[it]) {
                    dp[is][it] += dp[is - 1][it - 1];
                }
            }
        }
//        for (int si = 0; si < s.size(); si++) {
//            for (int ti = 0; ti < t.size(); ti++) {
//                printf("%d ", dp[si][ti]);
//            }
//            cout << endl;
//        }
        return dp[s.size() - 1][t.size() - 1];
    }
};

struct T {
    string s;
    string t;
    int expect;
};

TEST(Solution, test) {
    T ts[] = {
        {
            .s="rabbbit",
            .t = "rabbit",
            .expect=3,
        },
        {
            "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo",
            "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys",
            0
        }
    };

    for (T t : ts) {
        Solution solution;
        EXPECT_EQ(solution.numDistinct(t.s, t.t), t.expect);

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


