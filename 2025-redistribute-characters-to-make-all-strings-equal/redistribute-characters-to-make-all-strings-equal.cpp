class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26,0);
        int n=words.size();
        int tot=0;
        for(auto it:words) tot+=it.size();
        if(tot%n !=0) return false;

        for(auto it:words)
        {
            for(auto c:it)
              count[c-'a']++;
        }

        for(auto it:count)
        {
            if(it%n !=0) return false;
        }
        return true;
    }
};