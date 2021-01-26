class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        R = heights.size();
        C = heights[0].size();
        int right= 0;
        for (const auto & height: heights){
            for (const auto & h: height){
                right = max(right,h+1);
            }
        }
        int left = 0;
        while(left < right){
            int mid = (left + right) /2;
            if (possible(heights,mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
private:
    int R,C;
    vector<pair<int,int>> directions = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0},
    };
    bool possible(const vector<vector<int>> &heights, int k){
        queue<pair<int,int>> qq;
        qq.push(make_pair(0,0));
        vector<vector<bool>>  visited(R,vector<bool>(C));
        visited[0][0]=true;
        while(!qq.empty()){
            int qlen = qq.size();
            while(qlen > 0){
                auto now = qq.front();
                qq.pop();
                if (now.first == R-1 && now.second == C-1) return true;
                for (const auto &direction: directions){
                    int r = now.first + direction.first;
                    int c = now.second + direction.second;
                    if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c] || abs(heights[r][c] -heights[now.first][now.second]) > k)continue;
                    visited[r][c]=true;
                    qq.push(make_pair(r,c));
                }
                qlen--;
            }
        }
        return false;
    }
};


