class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res_sum = nums[0] + nums[1] + nums[2];
        int diff = abs(target - res_sum);

        for(int i = 0; i < n - 2; i++){
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                int d = abs(target - sum);

                if(d < diff){
                    diff = d;
                    res_sum = sum;
                
                }
                if(sum == target){
                    return sum;

                }
                if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return res_sum;
        
    }
};