#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<string> st;
    int n=s.length();
    for(int i=n-1; i>=0; i--){
        if(isdigit(s[i]) || isalpha(s[i])) st.push(string(1, s[i]));
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp="("+op1+s[i]+op2+")";
            st.push(temp);
        }
    }
    cout<<st.top()<<endl;
    return 0;
}