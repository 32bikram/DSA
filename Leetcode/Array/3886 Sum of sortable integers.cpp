
class Solution {
public:
    int is_sorted(vector<int>& nums, int start, int sze) {
        int count = 0;

        for (int i = start; i < start + sze - 1; i++) {
            if (nums[i] > nums[i + 1]) count++;
        }

        if (sze > 1 && nums[start + sze - 1] > nums[start])
            count++;

        return count;
    }

    bool is_sorted_whole(vector<int>& nums, int k) {
        int prev = INT_MIN;

        for (int start = 0; start < nums.size(); start += k) {
            int count = 0, descent = -1;

            for (int i = start; i < start + k - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    count++;
                    descent = i;
                }
            }

            if (k > 1 && nums[start + k - 1] > nums[start]) {
                count++;
                descent = start + k - 1;
            }

            if (count > 1) return false;

            int first, last;

            if (count == 1) {
                first = (descent == start + k - 1)
                            ? nums[start]
                            : nums[descent + 1];
                last = nums[descent];
            } else {
                first = nums[start];
                last = nums[start + k - 1];
            }

            if (prev > first) return false;

            prev = last;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> divisible;

        for (int k = 1; k <= nums.size(); k++) {
            if (n % k == 0) divisible.push_back(k);
        }

        int i = 0, j = 0, total_peaks = 0;
        bool all_sub_sorted = true;

        while (i < divisible.size()) {
            j = divisible[i];
            all_sub_sorted = true;
            total_peaks = 0;

            for (int t = 0; t < nums.size(); t += j) {
                int peaks = is_sorted(nums, t, j);

                if (peaks > 1) {
                    all_sub_sorted = false;
                    break;
                }
                else total_peaks += peaks;
            }

            if (all_sub_sorted) {
                if (is_sorted_whole(nums, j)) ans += j;
            }

            i++;
        }

        return ans;
    }
};
