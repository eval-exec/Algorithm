
class Solution {
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rets;
        return combinationSum(candidates,candidates.size()-1,target);
    }
    private:
    map<pair<int,int>,vector<vector<int>>> mm;
    vector<vector<int>> combinationSum(vector<int>& candidates,int end, int target) {
        auto f = mm.find(make_pair(end,target));
        if (f != mm.end()) return f->second;
        vector<vector<int>> rets;
        for (int e = 0; e <= end; e++){
            int n = 1;
            while(target - n*candidates[e] >= 0){
                vector<int> ns;
                for (int ni = 0;ni< n;ni++){
                    ns.push_back(candidates[e]);
                }
                
                if (target == n*candidates[e]){
                    rets.push_back(ns);
                }else if (e> 0){
                    auto r1 = combinationSum(candidates,e-1,target-n*candidates[e]);
                    for (int ri = 0; ri < r1.size();ri++){
                        r1[ri].insert(r1[ri].end(),ns.begin(),ns.end());
                    }
                    if (!r1.empty()) rets.insert(rets.end(),r1.begin(),r1.end());
                }
                n++;
            }
        }
        mm[make_pair(end,target)] = rets;
        return rets;
    }
};

