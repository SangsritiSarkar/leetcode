class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0,c0=0,cnt=0,n=nums.size();
        int ws=0;
        while(j<n)
        {
            ws+=nums[j];

            while(i<j and (nums[i]==0 || ws>goal)) {
                if(nums[i]==0) c0++;
                else c0=0;
                ws-=nums[i];
                i++;
            }

            if(ws==goal) cnt+=1+c0;
            j++;
        }
        return cnt;

    }
};