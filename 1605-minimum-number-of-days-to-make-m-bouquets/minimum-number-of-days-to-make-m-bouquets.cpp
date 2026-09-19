class Solution {
public:
    bool possible(vector<int>& bloomDay, int d, int m, int k){
        int c=0,cnt=0;
        for(int i=0;i<=bloomDay.size()-1;++i){
            if(bloomDay[i]<=d) c++;
            else{
                cnt+=c/k;
                c=0;
            }
        }
        cnt+=c/k;
        if(cnt>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=INT_MAX, high=INT_MIN,i;
        for(auto it:bloomDay){
            low=min(low,it); high=max(high,it);
        }
        if(bloomDay.size()< ((long long)m * k)) return -1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay, mid, m, k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};