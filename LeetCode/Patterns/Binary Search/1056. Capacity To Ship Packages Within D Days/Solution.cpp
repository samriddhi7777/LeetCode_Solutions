class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            int currentWeight = 0;
            int requiredDays = 1;

            for(int weight : weights){
                if(currentWeight + weight <= mid){
                    currentWeight += weight;
                }
                else{
                    requiredDays++;
                    currentWeight = weight;
                }
            }
            if(requiredDays <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};