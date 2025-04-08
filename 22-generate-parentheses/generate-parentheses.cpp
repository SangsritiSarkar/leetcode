class Solution {
public:
    bool isvalid(string s, int n){
        int cnt=0;
        for(auto c:s){
            if(c=='(') cnt++;
            else cnt--;
            if(cnt>n or cnt<0) return false;
        }
        if(cnt==0) return true;
        return false;
    }
    void solve(string &s, int n, vector<string> &ans){
        if(s.size()==2*n){
            if(isvalid(s,n)) ans.push_back(s);
            return;
        }
        s.push_back('(');
        solve(s,n,ans);
        s.pop_back();
        s.push_back(')');
        solve(s,n,ans);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(s,n,ans);
        return ans;
    }
};