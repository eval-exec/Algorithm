class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> nows;
        int nows_len = 0;
        vector<string> rets;
        for (int i = 0;i < words.size();i++){
            if (nows_len + nows.size() + words[i].size()> maxWidth){
                rets.push_back(distri(nows,nows_len,maxWidth));
                nows.clear();
                nows_len = 0;
                i--;
            }else{
                nows.push_back(words[i]);
                nows_len += words[i].size();
            }
        }
        if (!nows.empty()) rets.push_back(distri_last(nows,maxWidth));
        return rets;

    }
private:
    string distri_last(const vector<string> & strs,const int & maxWidth){
        string ret;
        for (int i = 0;i < strs.size();i++){
            ret += strs[i];
            if (i != strs.size() - 1){
                ret += " ";
            }
        }
        while(ret.size() < maxWidth){
            ret += " ";
        }
        return ret;
    }
    string distri(const vector<string> & strs, int all_len,const  int& maxWidth){
        if (strs.size() == 1){
            string now = strs[0];
            while(now.size() < maxWidth){
                now += " ";
            }
            return now;
        }
        int slots = strs.size() - 1;
        int allspace = maxWidth - all_len;
        int ava = allspace / slots;
        int more = allspace - ava * slots;
        string ret;
        for (int i = 0;i < strs.size();i++){
                ret += strs[i];
            if (i != strs.size() - 1){
                ret += spaces(ava);
                if (more > 0){
                    ret += " ";
                    more--;
                }
            }
        }
        return ret;
    }
    string spaces(int n){
        string ret;
        while(n > 0){
            ret += " ";
            n--;
        }
        return ret;
    }
};

