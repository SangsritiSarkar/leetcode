class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        vector<string> order;
        for(auto it:arr)
        {
            if(!mp[it]) order.push_back(it);
            mp[it]++;
        }
        for(auto it:order) if(mp[it]==1 and --k==0) return it;
        return "";
        
    }
};