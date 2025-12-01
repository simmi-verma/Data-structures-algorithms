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
    cin >> s;

    // 1: Reverse string
    reverse(s.begin(), s.end());

    // 2: Swap brackets
    for(char &c : s){
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    stack<char> st;
    string res = "";

    // 3: Convert reversed string to postfix
    for(int i = 0; i < s.length(); i++){
        char c = s[i];

        // Operand
        if(isalpha(c) || isdigit(c)){
            res += c;
        }
        // '(' goes to stack
        else if(c == '('){
            st.push(c);
        }
        // ')' pop until '('
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();  // remove '('
        }
        // Operator
        else {
            // Right-associative ^
            if(c == '^'){
                while(!st.empty() && priority(c) <= priority(st.top())){
                    res += st.top();
                    st.pop();
                }
            } 
            // Left-associative operators +, -, *, /
            else{
                while(!st.empty() && priority(c) < priority(st.top())){
                    res += st.top();
                    st.pop();
                }
            }
            st.push(c); // <-- required push (your code missed this)
        }
    }

    // Pop remaining
    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    // 4: Reverse postfix to get prefix
    reverse(res.begin(), res.end());

    cout << res << endl;
    return 0;
}
