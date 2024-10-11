class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Create a list of events with (time, friend, type_of_event)
        std::vector<std::tuple<int, int, int>> events;
        for (int i = 0; i < n; ++i) {
            events.emplace_back(times[i][0], i, 1); // Arrival event
            events.emplace_back(times[i][1], i, 0); // Leaving event
        }

        // Sort events by time, and if equal time, process leaving before arrival
        std::sort(events.begin(), events.end(), [](auto& a, auto& b) {
            if (std::get<0>(a) == std::get<0>(b)) {
                return std::get<2>(a) < std::get<2>(b); // Leave first
            }
            return std::get<0>(a) < std::get<0>(b);
        });

        // Priority queue to keep track of available chairs (smallest first)
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) availableChairs.push(i); // Initially all chairs available

        // Map to store which friend sits on which chair
        std::vector<int> assignedChairs(n, -1);

        // Process events
        for (auto& event : events) {
            int time = std::get<0>(event);
            int friendIdx = std::get<1>(event);
            int eventType = std::get<2>(event);

            if (eventType == 1) { // Arrival
                int chair = availableChairs.top();
                availableChairs.pop();
                assignedChairs[friendIdx] = chair;

                // If the current friend is the target friend, return the chair number
                if (friendIdx == targetFriend) {
                    return chair;
                }
            } else { // Leaving
                availableChairs.push(assignedChairs[friendIdx]); // Chair becomes available
            }
        }

        return -1; // Shouldn't happen if input is valid
    }
};


// 1, 4
// 2, 3
// 4, 6
// targetFriend = 1
// 