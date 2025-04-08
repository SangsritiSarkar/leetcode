class Solution {
public:
    
    void solve(string s, int n, vector<string> &ans, int open, int close){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            
            solve(s+'(',n,ans,open+1, close);
           
        }
        if(close<open){
           
            solve(s+')',n,ans,open, close+1);
            
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        int cnt=0;
        solve(s,n,ans,0,0);
        return ans;
    }
};