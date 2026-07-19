class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        // If the key does not exist
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>> &arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;

        string ans = "";

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Current timestamp is valid
            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second;      // Store current best answer
                left = mid + 1;             // Search for a later valid timestamp
            }
            else {
                right = mid - 1;            // Search in left half
            }
        }

        return ans;
    }
};