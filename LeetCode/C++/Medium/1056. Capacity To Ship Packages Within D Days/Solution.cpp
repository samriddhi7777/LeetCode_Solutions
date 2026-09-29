class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;

        for(int i = 0; i < weights.size(); i++){
            left = max(left,weights[i]);
            right += weights[i];
        }
        while(left < right){
            int mid = left + (right - left)/2;
            int currentWeight = 0;
            int requiredDays = 1;

            for(int i = 0; i < weights.size(); i++){
                if(currentWeight + weights[i] > mid){
                    requiredDays++;
                    currentWeight = weights[i];
                }
                else{
                    currentWeight += weights[i];
                }
            }
            if(requiredDays <= days){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
        
    }
};