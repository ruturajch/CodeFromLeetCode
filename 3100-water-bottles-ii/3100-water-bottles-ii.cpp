class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ful = 0;
        int emp = numBottles;
        int b = numBottles;
        while(emp >= numExchange){
            emp = emp - numExchange;
            b++;
            emp++;
            numExchange++;
        }
        return b;
    }
};