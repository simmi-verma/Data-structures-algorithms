#include <bits/stdc++.h>
using namespace std;

int priority(char c){
 if(c=='+' || c=='-') return 1;
 if(c=='*' || c=='/') return 2;
 if(c=='^') return 3;
 return -1;
}
int main(){
    string s;
    cin>>s;
    stack<string> st;
    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i]) || isalpha(s[i])) st.push(string(1,s[i]));
        else {
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp="("+op2+s[i]+op1+")";
            st.push(temp);
        }
    }
    cout<<st.top()<<endl;
    return 0;
}