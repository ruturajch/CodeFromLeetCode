class Solution {
private:
    int partition(vector<int>& nums, int begin,int end){
        int piviot = nums[end];
        int i = begin;
        for(int j = begin; j <= end; j++){
            if(nums[j] < piviot){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[end]);
        return i;
    }
    void merge(vector<int>& nums, int begin, int end)
    {  
        if(begin < end){
            int piviot = partition(nums, begin, end);
            merge(nums, begin, piviot - 1);
            merge(nums, piviot + 1, end);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums;
    }
};