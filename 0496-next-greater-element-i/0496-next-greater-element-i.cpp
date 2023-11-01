class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    //vector<int> helperVector(n, -1);
    unordered_map<int, int> um;
    //um[nums2[n-1]] = -1;
    //int cur = nums2[n-1];

    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++){
            if(nums2[i] < nums2[j]){
                um[nums2[i]] = nums2[j];
                break;
            }else{
                um[nums2[i]] = -1;
            }
        }   
    }
    um[nums2[n-1]] = -1;
    vector<int> ansVector;
    for (int i = 0; i < nums1.size(); i++)
    {
        ansVector.push_back(um[nums1[i]]);
    }
    return ansVector;
}
};