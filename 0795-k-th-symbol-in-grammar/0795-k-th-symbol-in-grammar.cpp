class Solution {
public:
    int kthGrammar(int n, int k) {
    int cur = 0;
    int l = 0;
    int r = pow(2,(n - 1));
    for(int i = 1; i < n; i++){
        int mid = (l + r)/2;
        if(k <= mid){
            r = mid;
        }else{
            l = mid +1;
            cur = cur ^ 1;
        }
    }
    return cur;
}
};