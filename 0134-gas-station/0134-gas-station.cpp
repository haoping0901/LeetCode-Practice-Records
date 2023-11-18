class Solution {
    bool direction = true; /* true for right, false for left */
    int begin = 0, end = 0, gas_diff, gas_surplus, vec_size;
public:
    void check_idx() {
        if (begin < 0) {
            begin = vec_size - 1;
        }

        if (end == vec_size) {
            end = 0;
        }
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vec_size = gas.size();

        gas_diff = gas.at(end) - cost.at(end);
        gas_surplus += gas_diff;

        if (gas_surplus >= 0) {
            end++;
        } else {
            begin--;
            direction = false;
        }
        check_idx();
        
        while (begin != end) {
            if (direction) {
                gas_diff = gas.at(end) - cost.at(end);
            } else {
                gas_diff = gas.at(begin) - cost.at(begin);
            }

            gas_surplus += gas_diff;

            if (gas_surplus >= 0) {
                end++;
                direction = true;
            } else {
                begin--;
                direction = false;
            }
            check_idx();
        }

        if (gas_surplus < 0) {
            return -1;
        } else {
            return begin;
        }
    }
};