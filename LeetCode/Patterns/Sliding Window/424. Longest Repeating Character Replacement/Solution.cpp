class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for(int right = 0; right < n; right++){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            int windowLength = right - left + 1;
            int replacements =  windowLength - maxFreq;
            while(replacements > k){
                freq[s[left] - 'A']--;
                left++;
                windowLength = right - left + 1;
                replacements = windowLength - maxFreq;
            }
        
        maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
        
    }
};