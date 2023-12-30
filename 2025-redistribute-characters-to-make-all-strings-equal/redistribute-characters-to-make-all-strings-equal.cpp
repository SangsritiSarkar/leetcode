class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        int n=words.size();
        int tot=0;
        for(auto it:words) tot+=it.size();
        if(tot%n !=0) return false;

        for(auto it:words)
        {
            for(auto c:it)
              mp[c]++;
        }

        for(auto it:mp)
        {
            int freq=it.second;
            if(freq%n !=0) return false;
        }
        return true;
    }
};