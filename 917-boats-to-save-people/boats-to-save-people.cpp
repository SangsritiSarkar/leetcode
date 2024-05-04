class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=0,l=0,r=people.size()-1,sum;
        sort(people.begin(),people.end());
        while(l<=r)
        {
           sum=people[l]+people[r];
           if(sum<=limit)
           {
            cnt++; l++; r--;
           }
           else{
            cnt++;r--;
           }
        }
        return cnt;
        
    }
};