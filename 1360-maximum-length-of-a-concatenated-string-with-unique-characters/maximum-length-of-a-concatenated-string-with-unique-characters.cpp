class Solution {
public:
    unordered_map<string, int> mp;
    bool common(string &ori, string temp)
    {
        int arr[26]={0};
        for(char &ch:ori)
        {
            if(arr[ch-'a']>0) return true;
            arr[ch-'a']++;
        }
        for(char &ch:temp)
        {
            if(arr[ch-'a']>0) return true;
        }
        return false;
    }
    int solve(int ind, string temp, vector<string>& arr, int n)
    {
        if(ind>=n) return temp.size();
        if(mp.find(temp)!=mp.end()) return mp[temp];
        int pick=0,not_pick=0;
        if(common(arr[ind],temp)){
            not_pick=solve(ind+1,temp,arr,n);
        }
        else
        {
            not_pick=solve(ind+1,temp,arr,n);
            pick=solve(ind+1,temp+arr[ind],arr,n);
        }
        return mp[temp]=max(pick,not_pick);
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        mp.clear();
        int n=arr.size();
        return solve(0,temp,arr,n);
    }
};