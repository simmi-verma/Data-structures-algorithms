#include <bits/stdc++.h>
using namespace std;
int  priority(char c){
 if(c=='+' || c=='-') return 1;
 if(c=='*' || c=='/') return 2;
 if(c=='^') return 3;
 return -1;
}
int main(){
    string s;
    cin>>s;
    stack<char> st;

    string res="";
    for (int i=0 ; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z' ) || (s[i]>=0 && s[i]<=9)){
            res+=s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while( !st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
    return 0;
}