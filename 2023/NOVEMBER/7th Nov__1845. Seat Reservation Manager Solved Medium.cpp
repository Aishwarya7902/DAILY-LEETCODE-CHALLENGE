PROBLEM:https://leetcode.com/problems/seat-reservation-manager/description/?envType=daily-question&envId=2023-11-06
VIDEO:https://www.youtube.com/watch?v=fjwHZNvbr7g

/*
  METHOD 1
  NAIVE
  TC:
  SC:
*/


/*
  METHOD 2
  TC:O(nlogn)+O(logn)
  SC:o(n)
*/

class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push(i);//nlogn
        }
    }
    
    int reserve() {
        int seat=pq.top();
        pq.pop();//logn
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber); //logn
    }
};
