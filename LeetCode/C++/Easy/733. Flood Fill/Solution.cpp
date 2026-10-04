class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &image, int orignalColor,int newColor){
        int rows = image.size();
        int cols = image[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols){
            return;
        }
        if(image[r][c] != orignalColor){
            return;
        }
        image[r][c] = newColor;

        dfs(r + 1, c, image, orignalColor, newColor);

        dfs(r - 1, c, image, orignalColor, newColor);

        dfs(r, c + 1, image, orignalColor, newColor);

        dfs(r, c - 1, image, orignalColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orignalColor = image[sr][sc];
        if(orignalColor == color){
            return image;
        }
        dfs(sr,sc,image,orignalColor,color);

        return image;
        
    }
};