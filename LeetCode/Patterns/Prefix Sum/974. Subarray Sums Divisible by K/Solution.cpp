class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int sum = 0;
        int res = 0;

        freq[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];

            int rem = sum % k;
            if(rem < 0)
               rem += k;
            
            res += freq[rem];
            freq[rem]++;
        }
        return res;
        
    }
};