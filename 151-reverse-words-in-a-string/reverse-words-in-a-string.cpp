class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="",ans="";
        
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' '){
                  if(i==n-1 or i==0) continue; //ignore start and end space
                  else if(s[i-1]==' ' and ans!="") continue; //ignore continue spaces
                  else if(ans!="") ans=temp+" "+ans; //not space even before beginning
                  
                  else ans=temp;
                  temp="";
            }
        }
        cout<<temp;
        if(temp!="") {
            if(ans!="") ans=temp+' '+ans;
            else ans=temp;
        }
        return ans;
    }
};