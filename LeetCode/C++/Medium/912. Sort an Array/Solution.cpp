class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        int i = low;
        for(int j = low ; j < high; j++){
            if(nums[j] < pivot){
            swap(nums[i] , nums[j]);
            i++;
        }
        }
        swap(nums[i], nums[high]);
        return i;
        

    }
    
    void quickSort(vector<int>& nums, int low, int high){
        if(low < high){
        int pivotIndex = partition(nums, low, high);
        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1 ;

        quickSort(nums,low,high);

    
            
                
                
        return nums;    
        }
        
        
    };
    
