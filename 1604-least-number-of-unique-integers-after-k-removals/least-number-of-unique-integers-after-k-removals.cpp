class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr) mp[it]++;
        vector<int> f;
        for(auto it:mp) f.push_back(it.second);
        sort(f.begin(),f.end());
        while(k>0 and f.size()>0)
        {
            k--;
            f[0]--;
            if(!f[0]) f.erase(f.begin());
        }
        return f.size();
    }
};