
class Solution {
public:
    int is_sorted(vector<int>& nums, int start, int sze) {
        int count = 0, idx = start;

        for (int i = start; i < start + sze - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                idx = i + 1;
            }
        }

        if (sze > 1 && nums[start + sze - 1] > nums[start]) {
            count++;
            idx = start;
        }

        if (count > 1) return -1;

        return idx;
    }

    bool is_sorted_whole(vector<int>& nums, int k) {
        int prev_end = -1;

        for (int start = 0; start < nums.size(); start += k) {
            int idx = is_sorted(nums, start, k);

            if (idx == -1) return false;

            int end_idx = start + (idx - start + k - 1) % k;

            if (prev_end != -1 && nums[prev_end] > nums[idx])
                return false;

            prev_end = end_idx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> divisible;

        for (int k = 1; k <= nums.size(); k++) {
            if (n % k == 0) divisible.push_back(k);
        }

        int i = 0, j = 0;
        bool all_sub_sorted = true;

        while (i < divisible.size()) {
            j = divisible[i];
            all_sub_sorted = true;

            for (int t = 0; t < nums.size(); t += j) {
                int idx = is_sorted(nums, t, j);

                if (idx == -1) {
                    all_sub_sorted = false;
                    break;
                }
            }

            if (all_sub_sorted && is_sorted_whole(nums, j))
                ans += j;

            i++;
        }

        return ans;
    }
};
