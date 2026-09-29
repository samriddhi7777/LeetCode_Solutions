class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPiles = 0;
        for(int i = 0; i < piles.size(); i++){
            maxPiles = max(maxPiles, piles[i]);
        }
        int left = 1;
        int right = maxPiles;

        while(left < right){
            int mid = left + (right - left)/2;
            long long hours = 0;
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + mid - 1) / mid;
            }
            if(hours <= h){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
        
    }
};