class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        int ans=0;
        for(auto c:tasks)
          mp[c-'A']++;
        priority_queue<int> pq;
        for(auto it:mp) if(it>0) pq.push(it);
        while(!pq.empty())
        {
            vector<int> temp;
            for(int i=1;i<=n+1;i++)
            {
                
                if(!pq.empty())
                {
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(auto it:temp)
            {
                if(it>0) pq.push(it);
            }

            if(pq.empty())
               ans+=temp.size();
            else 
               ans+=n+1;

        }
        return ans;
    }
};