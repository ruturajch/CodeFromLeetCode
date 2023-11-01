class Solution {
public:
    int maxNumberOfBalloons(string text) {
    int n = text.size();
    unordered_map<int, int> um;
    for(int i = 0; i < n; i++){
        um[text[i] - 'a']++;
    }    
    int cur = INT_MAX;
    cur = min(cur, um['b'-'a']);
    cur = min(cur, um['a'-'a']);
    cur = min(cur, um['l'-'a']/2);
    cur = min(cur, um['o'-'a']/2);
    cur = min(cur, um['n'-'a']);
    return cur;
}
};