PROBLEM:https://leetcode.com/problems/sort-characters-by-frequency/

/*METHOD 1:
TC:
SC:
pseudo code:
1.traverse and find frequency of each character and store in a map
2.now make a vector of pairs<char,int> and store all the values of map in the vector
3.now sort this vector based on a comparator in which we sort by value of map in decreasing order
4.now traverse the vector and  add to ans string   frequency times  of given character
5.return ans

*/

#include<bits/stdc++.h>
class Solution {  
public:
  static bool cmp(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
  }
    string frequencySort(string s) {
     unordered_map<char,int>freq;
      vector<pair<char,int>>res;
      string ans;
     for(auto x:s){
       freq[x]++;
     }
      //sort based on values in decreasing order
      for(auto it:freq){
        res.push_back(it);
      }
      sort(res.begin(),res.end(),cmp);
      
      for(auto it:res){
        int val=it.second;
        
          while(val--){
            ans+=it.first;
            
          }
        
        
      }
      return ans;
    }
};


/* USING HEAP
INTUTION :

1.The idea is to use max heap with nodes containing a pair {frequency, character}
2.Since the first element of the pair is frequency, we don't need to pass a custom comparator
3. Max heap will be constructed on the basis of frequency of characters
4. the root will contain the character with maximum frequency.

TC:O(log(n)) For Construction and extraction from heap
+
O(n) For storing the frequency in hashmap.
SC: o(n)
PSEUDO CODE:
1.take a map and store frequency of each character
2.TAVERSE MAP AND STORE IT'S FREQ,CHAR IN THE MAXHEAP
 Since the first element of the pair is frequency, we don't need to pass a custom comparator
3.take each node of heap and  make a string ( count, character )
create a string containing characters repeated count times ...and then pop
4.return final ans 
*/

#include<bits/stdc++.h>
class Solution {  
public:
  
    string frequencySort(string s) {
     unordered_map<char,int>freq;
      priority_queue<pair<int,char>>maxheap;
      
    string ans;
      //STORE FREQUENCY OF EACH CHARACTER IN A MAP
     for(auto x:s){
       freq[x]++;
     }
      //TAVERSE MAP AND STORE IT'S FREQ,CHAR IN THE MAXHEAP
      //Since the first element of the pair is frequency, we don't need to pass a custom comparator
      for(auto it:freq){
        maxheap.push({it.second,it.first});  
      }
      
      /*take each node of heap and  make a string ( count, character )

create a string containing characters repeated count times ...and then pop
*/
      
      while(maxheap.size()){
        ans+=string(maxheap.top().first,maxheap.top().second);  //LEARNING🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥
        maxheap.pop();
      }
      
      
     //return final ans 
      return ans;
    }
};
