class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>> qq;
        int R = grid.size();
        int C = grid[0].size();

        vector<vector<vector<bool>>> visited(R,vector<vector<bool>>(C,vector<bool>(k+1)));
        visited[0][0][k]=true;
        qq.push({0,0,k});
        int steps = 0;
        while(!qq.empty()){
            int qlen = qq.size();
            while(qlen> 0){
                auto now = qq.front();
                qq.pop();

                if (now[0] == R-1 && now[1] == C-1) return steps;
                for (const auto &di: directions){
                    int x = now[0] + di[0];
                    int y = now[1] + di[1];
                    if (x < 0 || x >= R || y < 0 || y >= C) continue;
                    if (grid[x][y] == 1){
                        if (now[2] > 0) {
                            if (visited[x][y][now[2]-1]) continue;
                            visited[x][y][now[2]-1]=true;
                            qq.push({x,y,now[2]-1});
                        }
                    }else{
                        if (visited[x][y][now[2]]) continue;
                        visited[x][y][now[2]]=true;
                        qq.push({x,y,now[2]});
                    }
                }
                qlen--;
            }
            steps++;
        }
        return -1;
    }
private:
    vector<vector<int>> directions = {
        {0,1},
        {0,-1},
        {-1,0},
        {1,0},
    };
};
