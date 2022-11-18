PROBLEM:https://leetcode.com/problems/ugly-number/
VIDEO: 

/*
my approach :TLE
pseudo code:
tc:O(n^2)
sc:O(n)
*/

class Solution {
private:
  bool isPrime(int n){
    for(int i=2;i<n;i++){
      if(n%i==0)return false;
    }
    return true;
  }
  
  
  //function to get the prime factoriztion
  vector<int> GetPrimeFactor(int n){
    vector<int>ans;
    int i=2;
    while(n){
      while(n>0 && isPrime(i) && n%i==0){
        ans.push_back(i);
        n/=i;
      }
    }
    return ans;
  }
public:
    bool isUgly(int n) {
      //base cases
      if(n>=1 && n<=3)return true;
      //if it is already a prime and is among 2,3,5 ...return true
      if(isPrime(n) && n==5)return true;
      //do prime factorization and check if all of them are among 2,3,5...and if yes ...just simply return true ...otherwise return false
      
      vector<int>curr=GetPrimeFactor(n);
      for(int i=0;i<curr.size();i++){
        if(curr[i]==2 || curr[i]==3 || curr[i]==5){
          continue;
        }
        else{
          return false;
        }
      }
      return true;
      
    }
};
/*METHOD 2 (RECURSIVE)
tc: O(logn) coz every time we are doing either n/2 or n/3 or n/5
sc:O(1)
*/
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)return false;
      if(n==1)return true;
      if(n%2==0)
        return isUgly(n/2);
      if(n%3==0)
        return isUgly(n/3);
      if(n%5==0)
        return isUgly(n/5);
      return false;
        
    }
};
