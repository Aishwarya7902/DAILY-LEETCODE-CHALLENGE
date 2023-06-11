PROBLEM :https://leetcode.com/problems/snapshot-array/description/

/*
Intuition
Instead of copy the whole array,
we can only record the changes of set.


Explanation
The idea is, the whole array can be large,
and we may take the snap tons of times.
(Like you may always ctrl + S twice)

Instead of record the history of the whole array,
we will record the history of each cell.
And this is the minimum space that we need to record all information.

For each A[i], we will record its history.
With a snap_id and a its value.

When we want to get the value in history, just binary search the time point.

Complexity
Time O(logS)
Space O(S)
where S is the number of set called.
*/

class SnapshotArray {
public:
    map<int,map<int,int>> snaps;
    int snapCount;
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> mp; mp[0] = 0;
            snaps[i] = mp;
        }
       snapCount=0;
    }
    
    void set(int index, int val) {
         snaps[index][snapCount]=val;
    }
    
    int snap() {
         return snapCount++;
          
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id); it--;
        return it->second;
    }
};
