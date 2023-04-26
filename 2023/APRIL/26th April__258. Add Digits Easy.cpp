PROBLEM:https://leetcode.com/problems/add-digits/description/
VIDEO:
BLOG:

/*
BRUTE FORCE :
TC:
SC:
*/

class Solution {
public:
    //helper function
    int findSum(int x){
        int sum=0;
        while(x){
            int rem=x%10;
            sum+=rem;
            x/=10;
        }
        return sum;
    }
    int addDigits(int n) {
        if(n<10)return n;
        int currSum=findSum(n);
        if(currSum<10)return currSum;
        return addDigits(currSum);
    }
};


/*
cleaner code
*/

class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num){
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        if(sum<10)return sum;
        else
         return addDigits(sum);
    }
};

/*
ITERATIVE METHOD
*/

class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>9){
           while(num){
            int rem=num%10;
            sum+=rem;
            num/=10;
            }
            num=sum;
            sum=0;
        }
        return num;
        
    }
};
