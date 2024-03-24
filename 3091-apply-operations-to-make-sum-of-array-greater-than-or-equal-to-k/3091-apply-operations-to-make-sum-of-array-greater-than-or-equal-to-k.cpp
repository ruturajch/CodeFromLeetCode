class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            double quotient = static_cast<double>(k) / i; // Perform the division with at least one operand as a double
            int result = static_cast<int>(ceil(quotient));
            //int d = static_cast<int>(ceil(k / i));
            ans = min(ans, result - 1 + i - 1);
            cout << result << endl;
        }
        return ans;
    }
};