class Solution {
public:
typedef pair<int, int> ppi;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> minh;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it:nums) mp[it]++;
        for(auto it:mp){
            minh.push({it.second, it.first});
            if(minh.size()>k) minh.pop();
        }
        while(minh.size()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};