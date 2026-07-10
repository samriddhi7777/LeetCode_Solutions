class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1;i < prices.size(); i++){
            int todayProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, todayProfit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
        
    }
};