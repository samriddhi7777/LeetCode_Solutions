class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int prefixSum = 0;
        int ans= 0;
        freq[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];

            if(freq.find(prefixSum - k) != freq.end())
               ans += freq[prefixSum - k];
               freq[prefixSum]++;

        }
        return ans;
    }
};