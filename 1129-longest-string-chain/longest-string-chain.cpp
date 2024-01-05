class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return (s1.size()<s2.size());
    }
  
    bool possible(string s1, string s2)
    {
        if(s1.size()!= s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size())
        {
            if(s1[i]==s2[j]) {
                i++; j++;
            }
            else i++;
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& arr) {
        int n=arr.size(),maxi=1;
        sort(arr.begin(), arr.end(), comp);
        //lambda func also correct
        // sort(arr.begin(),arr.end(),[](const string& s1, const string& s2){
        //     return s1.size() < s2.size();
        // });
    
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(possible(arr[i],arr[j]) && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(dp[i],maxi);

        }
        return maxi;
        
    }
};