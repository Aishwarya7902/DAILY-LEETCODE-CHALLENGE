PROBLEM :https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/?envType=daily-question&envId=2023-09-18
VIDEO (MIK BHAIYA):

/*

  BRUTE FORCE (SOLVED ON OWN)
  story-->

  (.)go to each row and count the no of soldiers
     make a pair of count,row_indx and push in a vector of pairs called vec
  (.)sort the vector vec..............since it is a vector of pairs...so it will sort based on the first element
  (.) pick the k smallest elements from vec and store their index in result
  (.) return result.

*/

class Solution {
public:
    //tc :o(m*n)
    //sc:o(m)
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>result;
        vector<pair<int,int>>vec;
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }

            }
            vec.push_back({cnt,i});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        while(k){
            result.push_back(vec[i].second);
            i++;
            k--;
        }
        return result;
        
    }
};


/*
  Method 2
  Binary Search
  tc: o(mlogn) // binary search 
     +o(mlogm) //sorting
     +o(k) // choosing k elements
  sc:o(m)
  */

class Solution {
public:
    
    int binarySearch(vector<int>&arr,int l ,int r){
        int result=-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid]==1){
                result=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result+1;

    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>result;
        vector<pair<int,int>>countOnes;


        for(int row=0;row<m;row++){
            int cntSoldiers=binarySearch(mat[row],0,n-1);
            countOnes.push_back({cntSoldiers,row});
        }

        //sorting
        sort(countOnes.begin(),countOnes.end());

        //taking k smallest elements
        int i=0;
        while(k){
            result.push_back(countOnes[i].second);
            i++;
            k--;
        }
        return result;
        
    }
};
