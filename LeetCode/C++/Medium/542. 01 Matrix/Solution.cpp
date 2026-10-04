class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist( rows, vector<int>(cols,-1));
            for(int r = 0; r < rows; r++){
                for(int c = 0; c < cols; c++){
                    if(mat[r][c] == 0){
                        q.push({r,c});
                        dist[r][c] = 0;
                    }
                }
            }
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
            
            if(r + 1 < rows && dist[r + 1][c] == -1){
                dist[r + 1][c] = dist[r][c] + 1;
                q.push({r + 1,c});
            }
            if(r - 1 >= 0 && dist[r - 1][c] == -1){
                dist[r - 1][c] = dist[r][c] + 1;
                q.push({r - 1, c});
            }
            if(c + 1 < cols && dist[r][c + 1] == -1){
                dist[r][c + 1] = dist[r][c] + 1;
                q.push({r, c + 1});
            }
            if(c - 1 >= 0 && dist[r][c - 1] == -1){
                dist[r][c - 1] = dist[r][c] + 1;
                q.push({r, c - 1});
            }
        }
        return dist;
        
    }
};