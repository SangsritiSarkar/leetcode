class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int last_smaller=INT_MIN,cnt=0,ans=1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==last_smaller+1){
                cnt++;
                last_smaller=nums[i];
            }
            else if(nums[i]!=last_smaller){
                cnt=1;
                last_smaller=nums[i];
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};