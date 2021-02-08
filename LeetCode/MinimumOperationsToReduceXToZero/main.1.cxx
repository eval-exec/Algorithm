class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> suml;
        int sum = 0;
        int count = INT_MAX;
        for (int i= 0;i< nums.size();i++){
            sum = sum+nums[i];
            suml[sum]=i;
            if (sum == x) count = min(count,i+1);
        }
        if (sum == x) return nums.size();
        if (sum < x) return -1;
        sum = 0;
        unordered_map<int,int> sumr;
        for (int i= nums.size()-1;i>=0;i--){
            sum = sum+nums[i];
            sumr[sum]=i;
            if (sum == x) count = min(count, nums.size() - i);
        }
        for (const auto &l : suml){
            auto r = sumr.find(x - l.first);
            if (r == sumr.end()) continue;
            count = min(count, int(l.second + 1 + nums.size() - r->second ));
        }
        if (count > nums.size() ) return -1;
        return count;
        
    }
};
