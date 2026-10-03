class Solution {
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &isVisited, int n){
        isVisited[node] = true;
        for(int neighbour = 0; neighbour < n; neighbour++){
            if(isConnected[node][neighbour] == 1 && !isVisited[neighbour]){
                dfs(neighbour,isConnected, isVisited, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                provinces++;
                dfs(i, isConnected, visited, n);

            }

        }
        return provinces;
        
    }
};