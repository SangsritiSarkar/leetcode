class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char c:s)
        {
            if(c=='(' or c=='{' or c=='[') st.push(c);
            else{
                if(st.empty()) return false; //closing not have corres open
                char ch=st.top();
                st.pop();
                if((c==')' and ch=='(') or (c=='}' and ch=='{') or (c==']' and ch=='[')) continue;//match
                else return false;//not match
            }
        }
        return st.empty();
    }
};