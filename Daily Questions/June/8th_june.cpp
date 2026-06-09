// Leetcode :- 2161 

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        int p = 0;
        int pivotCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) p++;
            else if (nums[i] == pivot) pivotCount++;
        }

        int a = 0;
        int k = p;
        int j = p + pivotCount;

        for (int i = 0; i < n; i++) {

            if (nums[i] < pivot) {
                ans[a] = nums[i];
                a++;
            }
            else if (nums[i] == pivot) {
                ans[k] = nums[i];
                k++;
            }
            else {
                ans[j] = nums[i];
                j++;
            }
        }

        return ans;
    }
};