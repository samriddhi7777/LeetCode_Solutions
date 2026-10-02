class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);

        stack<int> st;
        for(int i = 0; i < n * 2; i++){
            int index = i % n;
            while(!st.empty() && nums[index] > nums[st.top()]){
                int previousIndex = st.top();
                st.pop();

                ans[previousIndex] = nums[index];

            }
            if(i < n){
                st.push(index);
            }
        }
        return ans;
        
    }
};