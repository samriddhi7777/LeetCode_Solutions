class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int i = low;
        int pivot = nums[high];
        for(int j = low; j < high; j++){
            if(nums[j] < pivot){
                swap(nums[i],nums[j]);
                i++;

            }
        }
        swap(nums[i], nums[high]);
        return i;

    }
    int quickSelect(vector<int>& nums, int low, int high, int target){
        if(low == high){
            return nums[low];
        }
        int pivotIndex = partition(nums , low, high);
        if(pivotIndex == target){
            return nums[pivotIndex];
        }
        if(pivotIndex > target){
            return quickSelect(nums, low, pivotIndex - 1, target);

        }
        else{
            return quickSelect(nums, pivotIndex + 1, high, target);
        }

    }
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        return quickSelect(nums, 0 , nums.size() - 1, target);
        
    }
};