PROBLEM:https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2023-09-28
VIDEO:
//method 1 (on own)
//tc:o(n)
//sc:o(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        int k=0;
        int i=0,j=n-1;
        while(i<=j){
            if(nums[k]%2==0){
                result[i]=nums[k];
                i++;
            }
            else{
                result[j]=nums[k];
                j--;
            }
            k++;

        }
        return result;
    }
};


/*
method 2
tc:o(nlogn)
sc:o(1)
*/

class Solution {
public:
    static bool comparator(int &a,int &b){
        return a%2<b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums),end(nums),comparator);
        return nums;
    }
};

/*
method 3:
tc:o(n)
sc:o(1)
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};


    
