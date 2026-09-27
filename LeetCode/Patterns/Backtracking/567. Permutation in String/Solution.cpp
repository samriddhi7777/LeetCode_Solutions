class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if(m > n){
            return false;
        }
        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < m; i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                break;
            }
            if(i == 25){
                return true;
            }
        }
        for(int right = m; right < n; right++){
            freq2[s2[right] - 'a']++;
            freq2[s2[right - m] - 'a']--;
            bool same = true;

            for(int i = 0; i < 26; i++){
                if(freq1[i] != freq2[i]){
                    same = false;
                    break;
                }
            }
            if(same){
                return true;
            }
        }
        return false;
        
    }
};