class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it = freq.begin(); it != freq.end(); it++){
            pq.push({it->second,it->first});
        }
        string ans = "";
        pair<int,char> previous = {0,'#'};
        while(!pq.empty()){
            int count = pq.top().first;
            char current = pq.top().second;
            pq.pop();

            ans += current;
            count--;

            if(previous.first > 0){
                pq.push(previous);
            }
            previous = {count,current};
        }
        if(ans.size() != s.size()){
            return "";
        }
        return ans;
        
    }
};