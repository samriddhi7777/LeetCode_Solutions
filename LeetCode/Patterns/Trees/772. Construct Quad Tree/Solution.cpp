class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());

        
    }
    Node* build(vector<vector<int>> & grid, int row, int col, int size){
        int value = grid[row][col];
        bool same = true;

        for(int i = row; i < row + size; i++){
            for(int j = col; j < col + size; j++){
                if(grid[i][j] != value){
                same = false;
                break;
                }
            }
        
        if(!same)
           break;
    }
    if (same){
        return new Node(value == 1, true);
    }
    int half = size/2;

    Node* topLeft = build(grid, row , col, half);

    Node* topRight = build(grid, row, col + half, half);

    Node* bottomLeft = build(grid, row + half, col, half);

    Node* bottomRight = build(grid, row + half, col + half, half);

    Node* node = new Node(true, false);
    node->topLeft = topLeft;
    node->topRight = topRight;
    node->bottomLeft = bottomLeft;
    node->bottomRight = bottomRight;

    return node;

    }
};