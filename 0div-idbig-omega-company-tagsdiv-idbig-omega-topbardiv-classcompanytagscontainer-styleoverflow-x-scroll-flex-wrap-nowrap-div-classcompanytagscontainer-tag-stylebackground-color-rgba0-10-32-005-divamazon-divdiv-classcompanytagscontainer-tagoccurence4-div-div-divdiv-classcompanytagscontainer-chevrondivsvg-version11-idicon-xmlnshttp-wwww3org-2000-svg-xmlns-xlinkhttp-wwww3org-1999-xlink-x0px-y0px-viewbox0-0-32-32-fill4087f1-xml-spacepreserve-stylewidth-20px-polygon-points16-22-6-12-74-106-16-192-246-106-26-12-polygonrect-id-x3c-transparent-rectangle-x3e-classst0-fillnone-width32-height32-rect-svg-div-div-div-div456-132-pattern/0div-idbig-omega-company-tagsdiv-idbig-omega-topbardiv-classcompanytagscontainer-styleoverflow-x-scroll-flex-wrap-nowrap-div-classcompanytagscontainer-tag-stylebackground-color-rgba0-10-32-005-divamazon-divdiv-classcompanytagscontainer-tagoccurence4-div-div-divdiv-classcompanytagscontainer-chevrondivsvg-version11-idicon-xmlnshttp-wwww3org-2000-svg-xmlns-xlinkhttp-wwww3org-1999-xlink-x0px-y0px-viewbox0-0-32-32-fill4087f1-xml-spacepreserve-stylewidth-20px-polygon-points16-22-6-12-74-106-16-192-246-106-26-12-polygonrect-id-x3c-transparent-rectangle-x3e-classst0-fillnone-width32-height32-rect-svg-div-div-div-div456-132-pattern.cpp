class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        int thrd = std::numeric_limits<int>::min();
        std::stack<int> s;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < thrd) {
            return true;
            }
            while (!s.empty() && nums[i] > s.top()) {
                thrd = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
}
};