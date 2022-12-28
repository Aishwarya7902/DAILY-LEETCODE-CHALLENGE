1. if in an array ,if evry time u need a max ...while updating the elements of array ...its better to use a max heap🙂
similar thing applies to if u need min every time in array. 
  
  
  
2. if u wanna initialise a priority queue with given vector ,then instead of traversing array and pushing each element to queue ,what we can do is, simply 
initialise like this
 given vector -> vector<int> A;
priority_queue<int> pq(A.begin(), A.end()); //this is a short trick😅
