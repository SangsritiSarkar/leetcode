class Solution {
public:

    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(auto s: words)
        {
            string temp=s;
            reverse(temp.begin(),temp.end());
            if(temp==s) return s;
        }
        return ""; 
    
    }
};