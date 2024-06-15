#define Visited(x) (x) = (x) | 0xff

class Solution {
    size_t r_, c_;
    size_t r_size_, c_size_;
    uint8_t dir_;
public:
    void checkNextDir(vector<vector<int>>& matrix) {
        switch(dir_) {
            // case dirction is right
            case 0x0:
                if ((c_ + 1) != c_size_ && matrix[r_][c_+1] ^ 0xff)
                    ++c_;
                else if ((r_ + 1) != r_size_ && matrix[r_+1][c_] ^ 0xff) {
                        ++r_;
                        dir_ = 0x1;
                    }
                else 
                    dir_ = 0x4;
                break;
            // case dirction is down
            case 0x1:
                if ((r_ + 1) != r_size_ && matrix[r_+1][c_] ^ 0xff)
                    ++r_;
                else if (c_  != 0 && matrix[r_][c_-1] ^ 0xff) {
                        --c_;
                        dir_ = 0x2;
                    }
                else 
                    dir_ = 0x4;
                break;
            // case dirction is left
            case 0x2:
                if (c_ != 0 && matrix[r_][c_-1] ^ 0xff)
                    --c_;
                else if (r_  != 0 && matrix[r_-1][c_] ^ 0xff) {
                        --r_;
                        dir_ = 0x3;
                    }
                else 
                    dir_ = 0x4;
                break;
            // case dirction is top
            case 0x3:
                if (r_ != 0 && matrix[r_-1][c_] ^ 0xff)
                    --r_;
                else if (c_+1 != c_size_ && matrix[r_][c_+1] ^ 0xff) {
                        ++c_;
                        dir_ = 0x0;
                    }
                else 
                    dir_ = 0x4;
                break;
            default:
                dir_ = 0x4;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        r_ = 0, c_ = 0;
        r_size_ = matrix.size(), c_size_ = matrix[0].size();

        while (dir_ ^ 0x4) {
            ret.push_back(matrix[r_][c_]);
            Visited(matrix[r_][c_]);

            // check next direction
            checkNextDir(matrix);
        }

        return ret;
    }
};