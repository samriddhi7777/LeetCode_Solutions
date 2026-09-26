class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        int longest = 0;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(st.find(num - 1) == st.end()){
              int current = nums[i];
              int length = 1;
              while(st.find(current + 1) != st.end()){
                current++;
                length++;
              }
              longest = max(longest,length);

            

        }
        }
        return longest;
        
        
    }
};