class Solution {
public:
    int check(vector<int>& nums, int k) {
        int h = 0;
        for (int i = 0; i < nums.size(); i++) {
            h += (nums[i] + k - 1) / k;
        }
        return h;
    }
    int binary(vector<int>& nums, int h, int i, int j) {
        if (i < j) {
            int m = i + (j - i) / 2;  // Corrected midpoint calculation
            int k = check(nums, m);
            if (k <= h) {
                return binary(nums, h, i, m);
            } else {
                return binary(nums, h, m + 1, j);
            }
        }
        return i;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxele = 0;
        for (auto it : piles)
            maxele = max(maxele, it);

        int lo = 1;
        int hi = maxele;

        return binary(piles, h, lo, hi);
    }
};