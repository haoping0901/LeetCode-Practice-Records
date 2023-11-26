class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size();

        if (n == 0)
            return true;

        if (len < 3) {
            if (len == 1 && n==1 && flowerbed.at(0) == 0) {
                return true;
            } else if (len == 2 && flowerbed.at(0) == 0 && flowerbed.at(1) == 0 && n == 1) {
                return true;
            }
            return false;
        }

        int cnt=0, left=0, mid=1, right=2;
        if (flowerbed.at(mid) == 0) {
            left++;
            mid++;
            right++;

            if (flowerbed.at(0) == 0) {
                cnt++;
                flowerbed.at(0) = 1;
            }
        }


        for (; right<len; left++, mid++, right++) {
            if (flowerbed.at(left) == 0 && flowerbed.at(mid) == 0 && flowerbed.at(right) == 0) {
                cnt++;
                flowerbed.at(mid) = 1;
            }
        }
        
        if (mid < len && flowerbed.at(left) != 1 && flowerbed.at(mid) != 1) {
            flowerbed.at(mid) = 1;
            cnt++;
        }

        if (cnt >= n)
            return true;
        else 
            return false;
    }
};