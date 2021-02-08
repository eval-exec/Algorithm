class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ret;
        int len = path.size();
        int i = 0;
        string cur;
        while(i < len){
            char c = path[i];
            if (c == '/'){
                if (!cur.empty()){
                    if (cur == "."){
                    }else if (cur == ".."){
                        if (!ret.empty()) ret.pop();
                    }else{
                        ret.push(cur);
                        cout << ret.top();
                    }
                    cur.clear();
                }
            }else{
                cur.push_back(c);
            }
            i++;
        }
        if (!cur.empty()){
            if (cur == "."){
            }else if (cur == ".."){
                if (!ret.empty())ret.pop();
            }else {
                ret.push(cur);
            }
        }
        string final;
        if (!ret.empty()){
            while(!ret.empty()){
                string now = ret.top();
                ret.pop();
                final = "/"+now+final;
            }
            return final;
        }else{
            return "/";
        }
    }
};

