class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it = freq.begin(); it != freq.end(); it++){
            pq.push(it->second);
        }
        queue<pair<int,int>> q;

        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int current = pq.top();
                pq.pop();
                current--;
                if(current > 0){
                    q.push({current, time + n});
                }
            }
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
        
    }
};