class RandomizedSet {
    unordered_map<int, int> m; // value -> index
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (m.count(val) == 0) return false;
        if (v.back() != val) {
            m[v.back()] = m[val];
            swap(v[m[val]], v.back());
        }
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};