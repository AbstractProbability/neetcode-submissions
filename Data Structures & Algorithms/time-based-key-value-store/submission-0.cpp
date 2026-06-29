class TimeMap {
    unordered_map<string, map<int, string>> k_t_v;
public:
    TimeMap() {
        this->k_t_v = unordered_map<string, map<int, string>>();
    }
    
    void set(string key, string value, int timestamp) {
        if (!k_t_v.contains(key)) {
            k_t_v[key] = map<int, string>();
        }
        k_t_v[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!k_t_v.contains(key)) {
            return "";
        }
        auto t_v = k_t_v[key];
        auto ans = t_v.lower_bound(-timestamp);
        if (ans != t_v.end()) {
            return ans->second;
        }
        return "";
    }
};
