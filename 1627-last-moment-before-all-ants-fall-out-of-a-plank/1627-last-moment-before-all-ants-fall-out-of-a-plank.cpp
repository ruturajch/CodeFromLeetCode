class Solution {
public:
    
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    // Check if vectors are empty
    if (left.empty() && right.empty()) {
        return 0; // No ants, all fell already
    } else if (left.empty()) {
        sort(right.begin(), right.end());
        return n - right[0]; // Only ants on the right
    } else if (right.empty()) {
        sort(left.begin(), left.end(), greater<int>());
        return left[0]; // Only ants on the left
    }

    // Sort vectors
    sort(left.begin(), left.end(), greater<int>());
    sort(right.begin(), right.end());

    // Calculate the time at which the last ant falls
    return max(left[0], n - right[0]);
}
};