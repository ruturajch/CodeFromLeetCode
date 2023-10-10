class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        // gist: search nearest plate from left and from right, return the count_space - (plates in between)
        const int n = s.size() ;

        vector<int> pre(n), suf(n), cnt(n) ;
        pre[0] = s[0] == '|' ? 0 : -1 ;
        for(int i = 1 ; i < n ; i++) // for finding nearest plate from right (for start)
            pre[i] = s[i] == '|' ? i : pre[i - 1] ; 
        
        suf[n - 1] = s[n - 1] == '|' ? n - 1 : -1 ;
        for(int i = n - 2 ; i >= 0 ; i--) // for finding nearest plate from left (for end)
            suf[i] = s[i] == '|' ? i : suf[i + 1] ;
        
        cnt[0] = s[0] == '|' ;
        for(int i = 1 ; i < n ; i++) // for finding count of plates in between
            cnt[i] = cnt[i - 1] + (s[i] == '|') ;

        const int m = q.size() ;
        vector<int> ret(m, 0) ;

        for(int i = 0 ; i < m ; i++){
            int st = q[i][0], ed = q[i][1] ;

            int st_p = suf[ st ], ed_p = pre[ ed ] ; 
            if( st_p == -1 || ed_p == -1 || st_p > ed_p ) 
                continue ; // no between
            int total_bar = cnt[ ed_p ] - cnt[ st_p ] ;
            ret[i] = (ed_p - st_p ) - total_bar ;
        }

        return ret ;
    }
};