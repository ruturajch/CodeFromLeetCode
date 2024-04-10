class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> ansVector(n, 0);
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i = 0; i < n; i++){
            pq.push(i);
        }
        int i = 0;
        while(!pq.empty()){
            while(!pq.empty()){
                ansVector[pq.top()%n] = deck[i];
                i++;
                pq.pop();
                if(!pq.empty()){
                    int a = pq.top();
                    pq.pop();
                    pq.push(a+n);
                }
            }
        }
        return ansVector;
    }
};