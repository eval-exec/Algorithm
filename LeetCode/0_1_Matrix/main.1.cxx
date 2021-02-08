class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        R = matrix.size();
        C = matrix[0].size();
        queue<vector<int>> qq;
        for (int r = 0; r < R;r++){
            for (int c = 0; c < C;c++){
                if (matrix[r][c] == 0 ){
                    qq.push({r,c});
                }else{
                    matrix[r][c]=INT_MAX;
                }
            }
        }
        while(!qq.empty()){
            auto now = qq.front();
            int score = matrix[now[0]][now[1]];
            qq.pop();
            for (const auto & di: directions){
                int x = now[0]+di[0];
                int y = now[1]+di[1];
                if (x < 0 || x >= R || y < 0 || y >= C) continue; 
                if (matrix[x][y] > score+1){
                    matrix[x][y] = score+1;
                    qq.push({x,y});
                }
            }
        }
        return matrix;
    }
    int R,C;
    vector<vector<int>> directions = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0},
    };
};
