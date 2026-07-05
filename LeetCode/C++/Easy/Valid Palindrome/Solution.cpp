class Solution{
    public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(!(s[left] >= 'a' && s[left] <= 'z' ||
                 s[left] >= 'A' && s[left] <= 'Z' ||
                 s[left] >= '0' && s[left] <= '9')){
                     left++;
                 }
            else if(!(s[right] >= 'a' && s[right] <= 'z' ||
                 s[right] >= 'A' && s[right] <= 'Z' ||
                 s[right] >= '0' && s[right] <= '9')){
                     right--;
                 }
            else{
               char leftChar = s[left];
               char rightChar = s[right];
               
               if(s[left] >= 'A' && s[left] <= 'Z'){
                   leftChar = leftChar + 32;
        
                 
                }
                 if(s[right] >= 'A' && s[right] <= 'Z'){
                   rightChar = rightChar + 32;
        
                 
                }
                if(leftChar != rightChar){
                    return false;
                }
                left++;
                right--;
            }
            }
            return true;
        }
    }
