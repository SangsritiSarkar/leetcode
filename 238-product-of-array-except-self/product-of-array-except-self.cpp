class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> lp(n); //stores product of all before itself
        int right=1; //stores product of all after itself
        vector<int> ans(n);
        lp[0]=1; 
        for(int i=1;i<n;i++) lp[i]=lp[i-1]*nums[i-1];
        for(int i=n-1;i>=0;i--) {ans[i]=lp[i]*right; right*=nums[i];}
        return ans;
    }
};