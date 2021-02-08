#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

class UndergroundSystem {
  private:
    // stationName1+stationName2,sumCost,count
    unordered_map<string, pair<int, int>> memo;
    // user id, stationName , checkIn time.
    unordered_map<int, pair<string, int>> pps;

  public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        pps[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        auto prev = pps[id];
        int time_cost = t - prev.second;
        memo[prev.first + stationName].first += time_cost;
        memo[prev.first + stationName].second++;
        pps.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        auto f = memo[startStation + endStation];
        return f.first / (double(f.second));
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
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


