class Solution {
  public:
    int largest(vector<int> &arr) {
        int mx = arr[0];
        
        for(int i = 0; i < arr.size(); i++){
            mx = max(mx, arr[i]);
        }
        return mx;
        
    }
};
