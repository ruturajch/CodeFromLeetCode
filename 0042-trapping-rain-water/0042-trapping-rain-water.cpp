class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftVector(n, 0);
        vector<int> rightVector(n, 0);
        int minTemp = 0;
        for(int i = 0; i < n; i++){
            leftVector[i] = minTemp;
            minTemp = max(minTemp, height[i]);
        }
        minTemp = 0;
        for(int i = n-1; i >= 0; i--){
            rightVector[i] = minTemp;
            minTemp = max(minTemp, height[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            int tempSum = min(leftVector[i],rightVector[i]) - height[i];
            if(tempSum >=0)
                sum += tempSum;
        }
        return sum;
    }
};