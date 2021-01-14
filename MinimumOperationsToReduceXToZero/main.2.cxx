class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> sums;
        int sum = 0;
        int len = nums.size();
        int count = INT_MAX;
        for (int i = 0;i < len;i++){
            sum+=nums[i];
            sums[sum] = i;
            if (sum == x) count  = min(count,i+1);
        }
        if (sum == x) return len;
        if (sum < x) return -1;
        sum = 0;
        for (int i = len-1;i >= 0 ;i--){
            sum+=nums[i];
            if (sum == x) count  = min(count,len-i);
            const auto & f = sums.find(x - sum);
            if (f == sums.end()) continue;
            count = min(count, f->second+1+ len-i);
        }
        return count > nums.size() ? -1: count;
    }
};

