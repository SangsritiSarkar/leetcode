class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        int x,ans=0,cnt=1;
        unordered_set<int> st;
        for(auto it:nums) st.insert(it);
        for(auto it:nums)
        {
            if(st.find(it-1)==st.end())
            {
                cnt=1;
                x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                ans=max(cnt,ans);
            }
        }
        return ans;
    }
};