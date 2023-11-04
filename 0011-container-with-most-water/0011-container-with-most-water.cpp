class Solution {
public:
    int maxArea(vector<int>& height) {
        int n_height = height.size();
        int l_fence_idx = 0, r_fence_idx = n_height-1;
        int max_area = 0;

        while (l_fence_idx < r_fence_idx) {
            int level = min(height.at(l_fence_idx), height.at(r_fence_idx));
            int width = r_fence_idx - l_fence_idx;
            int cur_area = level * width;

            /* check the max area */
            if (cur_area > max_area)
                max_area = cur_area;
            
            /* update the fence position */
            if (height.at(l_fence_idx) < height.at(r_fence_idx))
                l_fence_idx++;
            else 
                r_fence_idx--;
        }

        return max_area;
    }
};