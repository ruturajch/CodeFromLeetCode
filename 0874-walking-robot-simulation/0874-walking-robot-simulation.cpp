class Solution {
    struct pair_hash{
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>& pair) const{
            auto hash1 = hash<T1> {}(pair.first);
            auto hash2 = hash<T2>{}(pair.second);
            return hash1 ^ (hash2 << 1);
        }
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash> myset;
        for(auto it : obstacles){
            myset.insert({it[0], it[1]});
        } 
        vector<pair<int, int>> dim {{0, 1},{1, 0},{0,-1},{-1, 0}};
        int curDir = 0;
        int curx = 0;
        int cury = 0;
        int ans = 0;

        for(int it : commands){
            if(it == -1){
                curDir++;
                curDir = curDir%4;
            }else if(it == -2){
                curDir--;
                if(curDir < 0){
                    curDir = curDir + 4;
                }
            }else{
                int tempx = curx;
                int tempy = cury;
                for(int i=0; i<it; i++)
                {
                    tempx = tempx + dim[curDir].first;
                    tempy = tempy + dim[curDir].second;
                    if(myset.find({tempx, tempy}) != myset.end()){
                        break;
                    }
                    curx = tempx;
                    cury = tempy;
                }
            }
            ans = max(curx * curx + cury * cury, ans);
        }
        return ans;
    }
};