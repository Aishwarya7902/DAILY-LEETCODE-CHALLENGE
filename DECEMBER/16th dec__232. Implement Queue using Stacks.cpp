PROBLEM: https://leetcode.com/problems/implement-queue-using-stacks/description/
VIDEO(STRIVER BHAIYA): https://www.youtube.com/watch?v=3Et9MrMc02A
prince bhaiya : https://www.youtube.com/watch?v=d0l8-7Bv-i0

/*
tc:
push:
tc:o(1)
sc: o(1) amortized , 
else O(n)

peek:
tc:o(1)
sc:o(1) amortized , 
else O(n)

empty:
tc:o(1)
sc:o(1)

*/

class MyQueue {
private:
stack<int>s1;
stack<int>s2;
public:
    MyQueue() {
      

    }
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        int curr;
      if(s2.size()!=0){
         curr=s2.top();
          s2.pop();
          
      }
      else{
          while(s1.size()!=0){
              s2.push(s1.top());
              s1.pop();
          }
          curr=s2.top();
          s2.pop();
          
      } 
      return curr; 
    }
    
    int peek() {
       int curr;
      if(s2.size()!=0){
         return s2.top();
          
      }
      else{
          while(s1.size()!=0){
              s2.push(s1.top());
              s1.pop();
          }
          
         return  s2.top();
          
      } 
     
    }
    
    bool empty() {
       return (s2.size()==0  && s1.size()==0);
    }
};

