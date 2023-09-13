class Solution {
public:
    void rec(vector<int>& ratings, int i, int j, vector<int>& assign){
        if(i < j){
            int m = (j+i)/2;
            rec(ratings, i, m, assign);
            rec(ratings, m+1, j, assign);
            if(ratings[m] > ratings[m+1] && assign[m] <= assign[m+1]){
                assign[m] = assign[m+1] + 1;
                int currElement = ratings[m];
                int currAssign = assign[m];
                for(int k = m - 1; k>= i; k--){
                    if(ratings[k] > currElement)
                        assign[k] = currAssign + 1;
                    else  break;
                    currElement = ratings[k];
                    currAssign = assign[k];
                }
            }else if (ratings[m] < ratings[m+1] && assign[m] >= assign[m+1]){
                assign[m+1] = assign[m] + 1;
                int currElement = ratings[m+1];
                int currAssign = assign[m+1];
                for(int k = m+2; k <= j; k++){
                    if(ratings[k] > currElement)
                        assign[k] = currAssign + 1;
                    
                    else break;
                    currElement = ratings[k];
                    currAssign = assign[k];
                }
            }
        }
    }
    
    int candy(vector<int>& ratings) {
        vector<vector<int>> v;//make vector for store element of rating with index and want get fist minimum rating element and give him minimum candy 1
        for(int i = 0; i < ratings.size(); i++){
            v.push_back({ratings[i],i});
        }
        sort(v.begin(),v.end());
        int n = ratings.size(),x = 0, k= 0;
        vector<int> ans(n,0);
        for(auto &i: v){
            x = 0;
            if(i[1]-1>=0&&ratings[i[1]]>ratings[i[1]-1]){//if ith index person have rating >= left person than he desirve more candy compare to left
                x = max(x,ans[i[1]-1]);
            }
            if(i[1]+1 < n&&ratings[i[1]]>ratings[i[1]+1]){//same for right.
                x = max(x,ans[i[1]+1]);
            }
            ans[i[1]] = x+1;//how much candy ith person get
            k += x+1;//total candy allocated
        }
        return k;
    }
};