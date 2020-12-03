#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class ProductOfNumbers {
private:
    vector<int> vv;
    set<int> zero;
public:
    ProductOfNumbers() {

    }

    void add(int num) {
        if (num == 0) {
            zero.insert(vv.size());
            vv.push_back(1);
            return;
        }
        if (vv.empty()) {
            vv.push_back(num);
            return;
        }
        vv.push_back(num * vv.back());
    }

    bool have_zero(int left, int right) {
        if (zero.empty()) return false;
        auto l = zero.lower_bound(left);
        if (l == zero.end()) return false;
        return *l >= left || *l <= right;
    }

    int getProduct(int k) {
        if (vv.size() == k) return vv.back();
        if (have_zero(vv.size() - k, vv.size() - 1)) return 0;
        return vv.back() / vv[vv.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */





struct T {

};

TEST(Solution, test) {
    T ts[] = {
            {

            },

    };

    Solution solution;

    for (T t : ts) {

    }
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}


