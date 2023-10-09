class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int right = -1;
        while (l <= r)
        {
            //cout << l << " " << r << endl;
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                right = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        l = 0;
        r = nums.size() - 1;
        int left = -1;
        while (l <= r)
        {
            // cout << l << " " << r << endl;
            int mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                left = mid;
                r = mid - 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        vector<int> ansVector;
        ansVector.push_back(left);
        ansVector.push_back(right);
        return ansVector;
    }
};