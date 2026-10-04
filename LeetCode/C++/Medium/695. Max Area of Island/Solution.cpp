class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> &grid){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols){
            return 0;
        }
        if(grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int area = 1;

        area += dfs(r + 1, c, grid);
        area += dfs(r - 1, c,grid);
        area += dfs(r, c + 1, grid);
        area += dfs(r, c - 1, grid);

        return area;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    int currentArea = dfs(r,c,grid);

                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;


        
    }
};