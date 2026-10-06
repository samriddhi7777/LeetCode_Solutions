class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;

        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], i, 0});
        }
        for(int i =0 ; i < k; i++){
            vector<int> current = pq.top();
            pq.pop();

            int value = current[0];
            int row = current[1];
            int col = current[2];

            if(col + 1 < n){
                pq.push({
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }
            if(i == k -1){
                return value;
            }
        }
        return -1;
        
    }
};