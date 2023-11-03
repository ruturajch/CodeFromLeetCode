class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int t = 0;
        vector<string> ansVector;
        for(int i = 1; i <= n && t < target.size(); i++){
            if(target[t] == i){
                ansVector.push_back("Push");
                t++;
            }else{
                ansVector.push_back("Push");
                ansVector.push_back("Pop");
            }
        }
        return ansVector;
    }
};