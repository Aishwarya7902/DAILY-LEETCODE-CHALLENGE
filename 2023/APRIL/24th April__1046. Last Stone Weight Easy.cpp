PROBLEM:https://leetcode.com/problems/last-stone-weight/
VIDEO:
BLOG:https://leetcode.com/problems/last-stone-weight/solutions/3448875/c-explained-easy-solution-priority-queue/?orderBy=hot

/*
Intuition ❤️❤️
To solve this problem, we can use a priority queue to keep track of the heaviest stones.
At each turn, we can pop the two heaviest stones from the heap, smash them together according to the given rules, 
and then push the resulting stone (if any) back onto the heap.
We repeat this process until there is at most one stone left in the heap.


Approach❤️❤️
In this code, we first create the priority queue by negating the values of the stones.
We then loop until there is at most one stone left in the heap. Inside the loop, 
we pop the two heaviest stones from the queue and check whether they are equal or not.
If they are not equal, we calculate the weight of the resulting stone and push it back onto the Queue
(priority queue heapify itself after every push operation).
Finally, we return the weight of the last remaining stone (or 0 if there are no stones left).
*/

//Time complexity: O(NLogN)
//Space complexity: O(N)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first!=second)
             pq.push(abs(first-second));
        }
        return pq.empty() ? 0 : pq.top();
    }
};
