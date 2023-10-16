class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a = {1};
        vector<int> b = {};
        for(int i = 0; i< rowIndex; i++){
            int n = a.size()+1;
            for(int j = 0; j< n; j++){
                if(j == 0){
                    b.push_back(a[0]);
                }else if(j == n-1){
                    b.push_back(a[n-2]);
                }else{
                    b.push_back(a[j-1]+a[j]);
                }
            }
            a = b;
            b = {};
        }
        return a;
    }
};