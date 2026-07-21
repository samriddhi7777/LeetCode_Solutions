class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int subarrays = 1;
        int currentSum = 0;

        for (int num : nums) {
            // If current number can fit in the current subarray
            if (currentSum + num <= maxSum) {
                currentSum += num;
            }
            // Otherwise, start a new subarray
            else {
                subarrays++;
                currentSum = num;

                // If more than k subarrays are needed,
                // maxSum is too small
                if (subarrays > k)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // Minimum possible answer
        int left = *max_element(nums.begin(), nums.end());

        // Maximum possible answer
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                // Try to minimize the answer
                right = mid - 1;
            } else {
                // Need a larger maximum sum
                left = mid + 1;
            }
        }

        return left;
    }
};