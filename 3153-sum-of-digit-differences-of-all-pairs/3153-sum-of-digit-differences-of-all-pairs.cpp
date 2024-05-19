class Solution {
public:
    
    #define ll long long
    
    long long sumDigitDifferences(vector<int>& nums) {
        queue<pair<int,int>> q;
        for(int num : nums) q.push({num/10, num%10});
        
        ll int ans = 0;
        while(q.size() > 0){
            int size = q.size();
            vector<int> digits(10,0);
            while(size--){
                pair<int,int> p = q.front();
                q.pop();
                
                int num = p.first, d = p.second;
                
                digits[d]++;
                
                if(num > 0) q.push({num/10, num%10});
            }
            
            for(int i=0;i<9;i++){
                for(int j=i+1;j<10;j++){
                    ans += digits[i]*digits[j];
                }
            }
        }
        return ans;
    }
};