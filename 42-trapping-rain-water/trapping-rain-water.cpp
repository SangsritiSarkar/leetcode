class Solution {
public:
    
    int trap(vector<int>& a) {
        int n=a.size(),ans=0;
        int l=0,r=n-1,leftmax=0,rightmax=0;
        while(l<=r)
        {
            if(a[l]<=a[r])
            {
                if(a[l]>=leftmax) leftmax=a[l];
                else ans+=leftmax-a[l];
                l++;
            }
            else
            {
                if(a[r]>=rightmax) rightmax=a[r];
                else ans+=rightmax-a[r];
                r--;
            }

        }
        
        return ans;
    }
};