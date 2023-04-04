PROBLEM:https://leetcode.com/problems/optimal-partition-of-string/description/
BLOG(aryan mittal):https://leetcode.com/problems/optimal-partition-of-string/solutions/3376693/image-explanation-3-approaches-o-1-space-c-java-python/?orderBy=most_votes
VIDEO:
1.(ARYAN)
2.(MAZHAR BHAIYA)
  
  /*
  getting TLE
  MY INITIAL THOUGHTS
  1.we will include chars in our window untill any char repeats itself
  2.once any char starts repeating itself ,we will increase cnt and remove all
  elements of this window and move to next window
  
  tc:
  sc:
  */
  
  class Solution {
public:
    int partitionString(string s) {
      int ans=0;
      int i=0,j=0;
      int n=s.size();
      unordered_map<char,int>mp;
      while(j<n){
          if(mp.find(s[j])==mp.end()){
              mp[s[j]]++;
              j++;
          }
          else{
              ans++;
              while(i!=j && i<n){
                  mp[s[i]]--;
                  if(mp.count(s[i])==0)mp.erase(s[i]);
                  i++;

              }
          }
      }
      return ++ans; 
    }
};

/*
optimisation
use a set/map
1.go on in  a partition untill u get a char repeated
2.we have to make minimum partition , so try to make every partition as much big as possible
3.go from i=0 to n
if u find a char already in map it means its time to make a partion
so simply increase cnt and set map to initial position
4.if not ...simply place the char in map
5.return cnt.

tc: o(n)
sc: o(26)
*/

class Solution {
public:
    int partitionString(string s) {
      int ans=1;
      int n=s.size();
      unordered_map<char,int>mp;
      for(int i=0;i<n;i++){
          if(mp.find(s[i])!=mp.end()){
              ans++;
              mp.clear() ; //reset map to initial position
          }
          mp[s[i]]++;
      }
      return ans; 
    }
};

/*
method 3
use an array

*/


/*
method 4
using bit manipulation
*/


