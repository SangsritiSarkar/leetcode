class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        for(string s: strs)
        {
            string temp=s;
            sort(begin(temp),end(temp));
            if(mp.find(temp)==mp.end())
            {
                mp[temp]=res.size();
                res.push_back({s});
            }
            else
            {
                res[mp[temp]].push_back(s);
            }
        }
        return res;
    }
};