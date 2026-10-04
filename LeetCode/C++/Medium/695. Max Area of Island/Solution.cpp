class Solution {
public:
    int rows, cols;
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= rows || col < 0 || col >= cols)
        return 0;

        if(grid[row][col] == 0)
            return 0;

            grid[row][col] = 0;

            int area = 1;

            area += dfs(grid, row - 1,col);
            area += dfs(grid, row + 1,col);
            area += dfs(grid, row, col - 1);
            area += dfs(grid, row, col + 1);

            return area;
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        rows = grid.size();
        cols = grid[0].size();

        int maxArea = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    maxArea= max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    
    }
};