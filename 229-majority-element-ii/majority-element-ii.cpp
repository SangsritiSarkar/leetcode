class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0, cnt2=0,ele1, ele2;
        for(auto it:nums)
        {
            if(cnt1==0 and it!=ele2) {cnt1=1; ele1=it;}
            else if(cnt2==0 and it!=ele1) {cnt2=1; ele2=it;}
            else if(it==ele1) cnt1++;
            else if(it==ele2) cnt2++;
            else {cnt1--; cnt2--;}
        }
        cnt1=0, cnt2=0;
        for(auto it:nums) {
            if(it==ele1) cnt1++;
            else if(it==ele2) cnt2++;
        }
        int mini=int(n/3)+1;
        vector<int> ans;
        if(cnt1>=mini) ans.push_back(ele1);
        if(cnt2>=mini) ans.push_back(ele2);
        return ans;
    }
};