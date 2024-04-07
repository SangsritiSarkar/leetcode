class Solution {
public:
    bool checkValidString(string s) {
        
       stack<char> st;
       stack<char> ast;
       for(int i=0; i<s.length(); i++)
       {
         char ch=s[i];
         if(ch == '(') st.push(i);
         else if(ch == '*') ast.push(i);
         else
         {
            if(!st.empty()) st.pop();
            else if(!ast.empty()) ast.pop();
            else return false;
         }
       }

       while(!st.empty() and !ast.empty())
       {
        if(st.top()>ast.top()) return false;
        st.pop(); ast.pop();
       }
        return st.empty();
    }
};