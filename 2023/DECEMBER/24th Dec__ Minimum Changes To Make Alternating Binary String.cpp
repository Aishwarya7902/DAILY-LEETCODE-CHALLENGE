PROBLEM: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2023-12-24
VIDEO (MIK BHAIYA) :https://www.youtube.com/watch?v=YB4oUR2Skfk

/*
  METHOD 1
  TC: o(n)
  SC: o(1)
*/

class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int start_with_0=0; //01010101 ........even index should have 0 and odd index should have 1
        int start_with_1=0; //10101010.........even index should have 1 and odd index should have 0

        for(int i=0;i<n;i++){
            if(i%2==0){ //even index
             if(s[i]=='0')start_with_1++;
             else start_with_0++;

            }
            else{ //odd_index
              if(s[i]=='0')start_with_0++;
              else start_with_1++;


            }
        }
        return min(start_with_0,start_with_1);
    }
};


/*
little optimization
*/

class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int start_with_0=0; //01010101 ........even index should have 0 and odd index should have 1
        

        for(int i=0;i<n;i++){
            if(i%2==0){ //even index
             if(s[i]=='1')
              start_with_0++;

            }
            else{ //odd_index
              if(s[i]=='0')start_with_0++;
            }
        }
        int start_with_1=n-start_with_0;
        return min(start_with_0,start_with_1);
    }
};
