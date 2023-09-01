class Solution {
public:
    static bool check(pair<int,int>& a, pair<int, int>& b){
        return a.first < b.first;
    }
    vector<int> partitionLabels(string s) {
        vector<pair<int, int> > um(26, make_pair(-1,-1));
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(um[s[i] - 'a'].first == -1){
                um[s[i] - 'a'] = make_pair(i,i);
            }else{
                um[s[i] - 'a'].second = i;
            }
        }
        sort(um.begin(), um.end(), check);
        vector<int> ans;
        pair<int, int> curr= make_pair(-1,-1);
        for(auto interval : um){
            if(interval.first != -1){
                //cout << interval.first << " " << interval.second << endl;
                if(curr.first == -1)
                    curr = interval;
                else if(curr.second < interval.first){
                    ans.push_back(curr.second -  curr.first + 1);
                    curr = interval;
                }
                else if(curr.second < interval.second){
                    curr.second =  interval.second;
                }
            }
        }
        ans.push_back(curr.second -  curr.first + 1);
        return ans;
    }
};