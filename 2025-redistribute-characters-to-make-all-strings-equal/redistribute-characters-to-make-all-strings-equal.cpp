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

        auto lambda=[&](int freq){
            return freq%n==0;
        };

        return all_of(begin(count),end(count),lambda);
    }
};