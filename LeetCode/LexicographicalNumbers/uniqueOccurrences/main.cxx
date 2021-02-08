class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mm;
        for (int n : arr){
            mm[n]+=1;
        }
        unordered_set<int> ss;
        for (auto m : mm){
            if (ss.count(m.second) == 0 ){
                ss.insert(m.second);
            }else{
                return false;
            }
        }
        return true;
    }
};
