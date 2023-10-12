
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // It's all about the binary search.
        // Clever of them to prevent you from using the binary search APIs.
        //
        // Phase 1: find the peak.
        //  - Given a range of the mountain,
        //    - Take the half point
        //       - if it's the peak (m[i] > m[i+1] and m[i] > m[i-1]), viola.
        //       - if it's on an uphill (m[i] < m[i+1]), 
        //         the peak should be on the right. Take the right half range.
        //       - if it's on a downhill (m[i] > m[i+1]), take the left range.
        //       - (up to 40 calls ==> ~13 half-points * 3 at the worst case)
        //
        // Phase 2: search for the target.
        //  - Do a binary search with each hill.
        //  - (up to 26 calls ==> ~13 half-points * 2 hills, at worst)

        // Typedef to avoid confusion.
        typedef int height_t;

        // Just a little crash-proof wrapper.
        auto getValue = [&](int idx) {
            if (idx < 0 || idx >= mountainArr.length())
                return -1;
            return mountainArr.get(idx);
        };

        // Phase 1: find the peak.
        int peak_idx; {
            int range_start_idx = 0;
            int range_end_idx = mountainArr.length();
            while (true) {
                peak_idx = range_start_idx + 
                    (range_end_idx - range_start_idx) / 2;

                height_t height_left = getValue(peak_idx-1);
                height_t height_this = getValue(peak_idx);
                height_t height_right = getValue(peak_idx+1);

                // If we found the peak, viola. Scrap it right now.
                if (height_left < height_this && height_this > height_right)
                    break;

                // If we're on an uphill, take the right range.
                if (height_this < height_right)
                    range_start_idx = peak_idx;

                // If we're on a downhill, take the left range.
                else if (height_this > height_right)
                    range_end_idx = peak_idx;
                
                /* else assert(false); */
            }
        }

        // Phase 2: search for the target.
        int target_idx; {
            // Phase 2.1: with the uphill.
            int range_start_idx = 0;
            int range_end_idx = peak_idx;
            while (true) {
                target_idx = range_start_idx +
                        (range_end_idx - range_start_idx) / 2;
                
                height_t height_this = getValue(target_idx);

                if (height_this == target)
                    return target_idx;
                else {
                    if (range_start_idx == range_end_idx - 1)
                        break;
                    else if (height_this < target)
                        range_start_idx = target_idx;
                    else if (height_this > target)
                        range_end_idx = target_idx;
                }
            }
        }{
            // Phase 2.2: with the downhill.
            int range_start_idx = peak_idx;
            int range_end_idx = mountainArr.length();
            while (true) {
                target_idx = range_start_idx +
                        (range_end_idx - range_start_idx) / 2;
                
                height_t height_this = getValue(target_idx);

                if (height_this == target)
                    return target_idx;
                else {
                    if (range_start_idx == range_end_idx - 1)
                        break; 
                    else if (height_this < target)
                        range_end_idx = target_idx;
                    else if (height_this > target)
                        range_start_idx = target_idx;
                }
            }
        }

        return -1;
    }
};