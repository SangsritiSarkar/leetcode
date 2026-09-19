class Solution {
public:
    int possible(vector<int>& weights, int cap, int d){
        int tot=0, cnt=1;
        for(auto it:weights){
            if(tot+it<=cap){
                tot+=it;
            }
            else{
                cnt++;
                tot=it;
            }
        }
        if(cnt<=d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN, high=0,mid;
        for(auto it:weights) {high+=it;low=max(low,it);}
        while(low<=high){
            mid=low+(high-low)/2;
            if(possible(weights, mid, days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};