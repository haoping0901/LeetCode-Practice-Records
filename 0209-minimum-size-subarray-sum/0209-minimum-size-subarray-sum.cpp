class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin=0, cnt=0, end=0;
        int tmp_cnt=cnt, tmp_begin, tmp_end;

        for (int i=0; i<nums.size(); i++) {

            if (cnt < target) {
                end = i;
            } 
            cnt += nums.at(i);

            if (cnt >= target) {
                tmp_cnt=cnt;
                tmp_begin=begin;
                tmp_end=i;
                
                while (tmp_cnt-nums.at(tmp_begin) >= target) {
                    tmp_cnt -= nums.at(tmp_begin);
                    tmp_begin++;
                }

                if ((tmp_end-tmp_begin) < (end - begin)) {
                    begin = tmp_begin;                    
                    end = tmp_end;
                    cnt = tmp_cnt;
                } 
            }
        }
        
        if (cnt >= target) {
            return end-begin+1;
        } else {
            return 0;
        }
    }
};