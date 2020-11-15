#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class SnapshotArray {

public:
    SnapshotArray(int length) {
        vs = vector<map<int, int>>(length);
        snap_now = 0;
    }

    void set(int index, int val) {
        vs[index][snap_now] = val;
    }

    int snap() {
        return snap_now++;
    }

    int get(int index, int snap_id) {
        auto &mm = vs[index];
        if (mm.empty()) {
            return 0;
        }
        auto l = mm.upper_bound(snap_id);
        if (it== snaps[index].begin()){
                        return 0;
        }
        l--;
        return l->second;
    }

private:
    vector<map<int, int>> vs;
    int snap_now;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
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


