class Solution {
public:
    int minDeletions(string s) {
        // Get the length of the input string.
        int n = s.length();
        
        // Initialize the answer variable to 0.
        int ans = 0;
        
        // Create a vector to store the frequency of each character in the string.
        vector<int> characters(26, 0);
        
        // Create an unordered set to keep track of unique frequencies encountered.
        unordered_set<int> st;
        
        // Count the frequency of each character in the string.
        for(int i = 0; i < n; i++) {
            characters[s[i] - 'a']++;
        }
        
        // Loop through the frequencies of characters (0 to 25).
        for(int i = 0; i < 26; i++) {
            int freq = characters[i];
            
            // If the frequency is 0, skip to the next character.
            if(freq == 0) continue;
            
            // If the frequency is not in the set, add it to the set.
            if(st.find(freq) == st.end()) {
                st.insert(freq);
            } else {
                // If the frequency is already in the set, we need to make it unique.
                int x = freq;
                while(x > 0) {
                    // Find the smallest unique frequency and update the answer.
                    if(st.find(x) == st.end()) {
                        ans += (freq - x);
                        st.insert(x);
                        break;
                    }
                    x--;
                }
                // If x becomes less than or equal to 0, we couldn't make it unique, so add the original frequency.
                if(x <= 0) ans += freq;
            }
        }
        
        // Return the final answer, which represents the minimum deletions needed.
        return ans;
    }
};