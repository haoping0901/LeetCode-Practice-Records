class Solution {
    size_t l_, r_, t_, d_;
public:
    inline void swap(int& a, int& b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    void RotateElement(vector<vector<int>>& matrix, const int& offset) {
        // swap the values of the four positions affected by the rotation.
        swap(matrix[t_][l_+offset], matrix[d_-offset][l_]);
        swap(matrix[d_-offset][l_], matrix[d_][r_-offset]);
        swap(matrix[d_][r_-offset], matrix[t_+offset][r_]);
    }

    void rotate(vector<vector<int>>& matrix) {
        // rotate from the outermost ring to the innermost ring.
        l_ = 0, r_ = matrix[0].size()-1;
        t_ = 0, d_ = matrix.size()-1;

        while (l_ < r_) {
            for (int offset = 0; offset < (r_-l_); ++offset)
                RotateElement(matrix, offset);

            ++l_, --r_, ++t_, --d_;
        }
    }
};

