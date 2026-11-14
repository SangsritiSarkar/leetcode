class Solution {
public:
typedef pair<int,int> ppi;

struct comp{
    bool operator()(ppi a, ppi b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
};

    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<ppi, vector<ppi>, comp> minh;
        for(auto it:nums) mp[it]++;
        for(auto it:mp){
            minh.push({it.second, it.first});
        }
        while(minh.size()){
            for(int i=1;i<=minh.top().first;++i) ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};