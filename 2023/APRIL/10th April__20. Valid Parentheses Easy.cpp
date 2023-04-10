PROBLEM: https://leetcode.com/problems/valid-parentheses/description/
VIDEO:  https://www.youtube.com/watch?v=3ssh_mk4LqY

/*
approach 1
using one stack

pseudo code
1.iterate on given string
2.if upcoming char is any of the open paranthesis
just push it in stack

3.if upcoming char is a closing bracket

then check if top has its corresponding opening bracket

....if yes ....we are gd to go....pop top of stack

....else return false from there itself

4.return true if stack is empty

tc:
sc:
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(st.empty() || ch=='(' ||ch=='{' || ch=='['){
                st.push(ch);
                continue;
            }
            if(ch==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else
                 return false;
            }
            if(ch==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else
                 return false;
            }
            if(ch=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else
                 return false;
            }
            
        }
        return st.size()==0;
    }
};
