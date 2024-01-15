class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        //vector<vector<int>> ans;
        
        unordered_map<int, int>mp;
        unordered_map<int,int> mpl;
        vector<int> win,lost;
        for(auto it:matches) mp[it[0]]=0;
        for(auto it:matches)
        {
           if(mp.find(it[1])!=mp.end())
           {
               mp[it[1]]++;
           }
           else mpl[it[1]]++;
        }
        
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(i->second==0) win.push_back(i->first);
            else if(i->second==1) lost.push_back(i->first);
        }
        for(auto i=mpl.begin();i!=mpl.end();i++)
        {
            if(i->second==1) lost.push_back(i->first);
        }
        sort(begin(win),end(win));
        sort(begin(lost),end(lost));
        return {win,lost};
    }
};