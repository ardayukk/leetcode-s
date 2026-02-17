class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value}); // timestamps increasing per key
    }

    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if(it == mp.end()) return "";

        auto &v = it->second; // sorted by timestamp
        int l = 0, r = (int)v.size() - 1;
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(v[mid].first <= timestamp){
                ans = mid;        // candidate
                l = mid + 1;      // try to find a later one
            }else{
                r = mid - 1;
            }
        }

        return (ans == -1) ? "" : v[ans].second;
    }
};
