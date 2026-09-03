class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> neg;
        vector<int> pos;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            
            else
                pos.push_back(nums[i]);
            
        }
        for(int i = 0; i < neg.size(); i++ ){
            neg[i] = neg[i] * neg[i];
        }
        reverse(neg.begin(), neg.end());

        for(int i = 0; i < pos.size(); i++){
            pos[i] = pos[i] * pos[i];
        }
        vector<int> result;
        int i = 0;
        int j = 0;

        while(i < neg.size() && j < pos.size()){
            if(neg[i] <= pos[j]){
               result.push_back(neg[i]);
               i++;

            }
        else{
            result.push_back(pos[j]);
            j++;
        }
        }
        while(i < neg.size()){
            result.push_back(neg[i]);
            i++;
        }
        while(j < pos.size()){
            result.push_back(pos[i]);
            j++;
        }
        return result;
   

        
    }

};