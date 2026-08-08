class Solution {
  public:
    int arraySum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
        }
        return sum;
        
    }
};