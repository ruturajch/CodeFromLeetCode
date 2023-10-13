class Solution {
public:
    void solve(vector<int>& a, int &pos){
        if(pos>=a.size())return;
        if(a[pos]<0 && pos>0){
            if(a[pos-1]>0){
                if(a[pos-1]>abs(a[pos])){
                    a.erase(a.begin()+pos);
                    solve(a,pos);
                }
                else if(a[pos-1]<abs(a[pos])){
                    a.erase(a.begin()+pos-1);
                    pos--;
                    solve(a,pos);
                }
                else{
                    a.erase(a.begin()+pos);
                    a.erase(a.begin()+pos-1);
                    pos-=2;
                    solve(a,pos);
                }
            }
        }
        pos++;
        solve(a,pos);
    }
    vector<int> asteroidCollision(vector<int>& a) {
        int pos=0;
        solve(a,pos);
        return a;
    }
};