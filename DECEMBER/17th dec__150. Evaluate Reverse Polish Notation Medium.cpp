PROBLEM:https://leetcode.com/problems/evaluate-reverse-polish-notation/
video:https://www.youtube.com/watch?v=BM-bu4tJz7U

/*
METHOD 1
TC: O(N)
SC:O(N)
PSEUDO CODE:
1.if current element is any of the operator then
2.take out two elements from stack and perform operation on them
3.push the result of above opertaion in stack
4.move forward

*/

#include<bits/stdc++.h>
class Solution {
private:
int Operate(int &a,int &b,string &s){
    if(s == "+"){
        return a+b;
    }
    if(s == "-"){
        return a-b;
    }
    if(s == "*"){
        return (long)a*(long)b;
    }
    if(s == "/"){
        return a/b;
    }
    
    return -1;
}
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for( string &token:tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                //top ke 2 elements ko nikalo and operate kar do
                //push result in stack
                int b =st.top();
                st.pop();
                int a =st.top();
                st.pop();
                /*note lets say 8/4 hence 8 will come first in stack 
                and 4 will later hence hence 4 will be on top of stack lets say it is b and then 8 will be below 4 in stack lets say it is a hence 
                in operation we will pass(8,4,"/")
                so that it will calculate as 8/4
                hence we pass a,b not as b,a
                */
                int result=Operate(a,b,token);
                st.push(result);
                
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
