class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // int n= nums.size();
        // set<vector<int>> st;
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=i+1;j<n;++j)
        //     {
        //         set<long long> s;
        //         for(int k=j+1;k<n;++k)
        //         {
        //             long long sum= nums[i]+nums[j];
        //             sum+=nums[k];
        //             long long f=target-(sum);
        //             if(s.find(f)!=s.end()){
        //                 vector<int> temp={nums[i],nums[j],nums[k],nums[f]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //             s.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());
        // return ans;

        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;++j)
            {
                if(j!=i+1 and nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);++k;--l;
                        while(k<l and nums[k]==nums[k-1]) ++k;
                        while(k<l and nums[l]==nums[l+1]) --l;
                    }
                    else if(sum<target) ++k;
                    else --l;
                }
            }
        }
        return ans;
    }
};