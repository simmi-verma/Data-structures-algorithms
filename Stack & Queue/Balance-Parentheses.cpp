#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(char ch:s){
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty()){
                cout<<"false"<<endl;
                return 0;
            }
            char top=st.top();
            st.pop();
            if(ch==')' && top=='(') continue;
            else if(ch=='}' && top=='{') continue;
            else if(ch==']' && top=='[') continue;
            else{
                cout<<"false"<<endl;
                return 0;
            }

        }
    }
    if (st.empty()) cout << "true";
    else cout << "false";
    return 0;

}