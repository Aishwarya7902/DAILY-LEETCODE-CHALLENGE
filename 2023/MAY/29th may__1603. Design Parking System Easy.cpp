PROBLEM: https://leetcode.com/problems/design-parking-system/description/
VIDEO : https://www.youtube.com/watch?v=ysZ7Rla4w7Y

/*
SELF
TC:O(1)
SC:O(1)
*/


class ParkingSystem {
public:
    int b,m,s;
    int currBig=0,currMed=0,currSmall=0;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
        
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(currBig<b){
                currBig++;
                return true;
            }
        }
        else if(carType==2){
            if(currMed<m){
                currMed++;
                return true;
            }
        }
        else if(carType==3){
            if(currSmall<s){
                currSmall++;
                return true;
            }
        }


     return false;   
    }
};
