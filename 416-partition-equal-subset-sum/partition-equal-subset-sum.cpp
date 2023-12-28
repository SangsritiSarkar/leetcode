class Solution {
public:
//space optimization in 1 array
    bool f(int n, int k, vector<int> &arr) {
        vector<bool> prev(k + 1, false);
        
        // base
        prev[0]=true;
        if(arr[0]<=k) prev[arr[0]]=true;
        

        //state
        for(int ind=1;ind<n;ind++)
        {
            
            for(int target=k;target>=0;target--)
            {
                bool notTaken=prev[target];

                bool taken=false;
                if(target>=arr[ind])
                    taken=prev[target-arr[ind]];
                
                prev[target]=taken || notTaken;
            }
            
        }

        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int tot=0;
        int k;
        for(int i=0;i<nums.size();i++) tot+=nums[i];

        if(tot%2) return false;
        else k=tot/2;
        
        return f(nums.size(),k,nums);
    }
};