class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= rows || col < 0 || col >= cols)
        return;

        if(grid[row][col] == '0')
        return;

        grid[row][col] = '0';

        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col -1 );
        dfs(grid, row, col + 1);
           
    }
    

    int numIslands(vector<vector<char>>& grid){

        rows = grid.size();
        cols = grid[0].size();

        int island = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    island++;
                    dfs(grid, i, j);
                }

            }
        }
        return island;
    }
};