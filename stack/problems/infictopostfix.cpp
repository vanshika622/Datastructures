#include<iostream>
#include<stack>
using namespace std;
int precedence(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='/'||ch=='*'){
        return 2;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
    return -1;
}
string infixtopostfix(string s){
    stack<char>st;
    string res;
    for(int i=0;i<s.length();i++){
    if(s[i]>='a'&& s[i]<='z'||s[i]>='A'&&s[i]<='Z'){
          res+=s[i];
    }
    else if(s[i]=='('){
        st.push(s[i]);

    }
    else if(s[i]==')'){
        while( st.top()!='('){
            res+=st.top();
            st.pop();
        }
        if(!st.empty()){
            
            st.pop();
        }
    }
    else{
        while(!st.empty()&& precedence(s[i])<precedence(st.top())){
            res+=st.top();
            st.pop();
        }
        st.push(s[i]);
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    }
    return res;
}
int main(){
    string s="(a+b/c-d*e)";
 cout<<infixtopostfix(s);


}