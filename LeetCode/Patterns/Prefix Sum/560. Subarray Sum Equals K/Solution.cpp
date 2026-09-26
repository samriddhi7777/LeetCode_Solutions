class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        int prefixsum = 0; 
        int count = 0;

        for(int num : nums){
            prefixsum += num;
            int required = prefixsum - k;
            if(mp.find(required) != mp.end()){
               count += mp[required];
        }
        
        mp[prefixsum]++;
        }
        return count;
        
    }
};