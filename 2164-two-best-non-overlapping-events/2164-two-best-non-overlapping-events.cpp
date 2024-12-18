class Solution {
    vector<vector<int>> rec_;

    int SearchNextIdx(const vector<vector<int>>& events, const int& idx) {
        int cur_end = events[idx][1];
        int l = idx + 1, r = events.size() - 1, m = l + ((r - l) >> 1);

        while (l < r) {
            if (cur_end >= events[m][0])
                l = m+1;
            else
                r = m;
            
            m = l + ((r - l) >> 1);
        }

        return m;
    }

    int FindBestEvents(const vector<vector<int>>& events, const int& idx, 
                       const int& cnt) {
    // At each selection, check if two events have already been selected 
    // (track the current count of selected events):
        // If yes, return the result.
        // Otherwise, continue the recursion.
        if (idx >= events.size() || cnt == 2)
            return 0;
        
        if (rec_[idx][cnt] != -1)
            return rec_[idx][cnt];
        
        // Iterate through all events, comparing the result of selecting or 
        // not selecting each event.
            // If selecting the event, recursively search for the next 
            // eligible event after this one.
            // If not selecting the event, similarly recursively search for 
            // the next event.
        // Selected
        int next_idx = SearchNextIdx(events, idx);
        int sel = events[idx][2] + ((events[next_idx][0] > events[idx][1]) ? 
                                  FindBestEvents(events, next_idx, cnt+1) : 0);

        // Non-selected
        int n_sel = FindBestEvents(events, idx+1, cnt);

        rec_[idx][cnt] = max(sel, n_sel);
        return rec_[idx][cnt];
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // DP
        // Each event has three possible scenarios:
            // Not selected
            // Selected for the first time
            // Selected for the second time
        rec_ = vector<vector<int>>(events.size(), vector<int>(3, -1));
        
        // To speed up finding the next eligible event, sort the events by 
        // their start time.
        // This enables the use of binary search to efficiently locate the 
        // first event that meets the criteria.
        sort(events.begin(), events.end());

        // For each event, decide whether to select it or not.
        // Since each event can lead to different choices, implement this 
        // logic using recursion.
        return FindBestEvents(events, 0, 0);
    }
};