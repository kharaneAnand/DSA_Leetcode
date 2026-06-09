# 🚀 229. Majority Element II | Boyer Moore Voting Algorithm | Find Elements Appearing More Than n/3 Times | Beats 100%

# Intuition
We need to find all elements appearing more than:

:contentReference[oaicite:0]{index=0}

times.

Important observation:
- There can be at most **2 majority elements**.

Why?
Because:
- Three different elements occurring more than `n/3` times is impossible.

We can solve this using:
1. Sorting
2. HashMap
3. Optimal Boyer Moore Voting Algorithm

# Approach 1: Sorting

# Intuition
1. Sort the array
2. Count frequency of consecutive elements
3. If frequency exceeds:

:contentReference[oaicite:1]{index=1}

add to answer.

# Complexity
- Time complexity:
  - `O(N log N)`

- Space complexity:
  - `O(1)` excluding sorting space

# Code
```cpp
class Solution {

public:

    vector<int> majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        int n = nums.size();

        if (n == 1)
            return nums;

        int cnt = 1;

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] == nums[i + 1]) {

                cnt++;
            }

            else {

                if (cnt > n / 3) {

                    ans.push_back(nums[i]);
                }

                cnt = 1;
            }
        }

        // Last element check
        if (cnt > n / 3) {

            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};
```

---

# Approach 2: HashMap Frequency Counting

# Intuition
Store frequency of every element using:
- `unordered_map`

Then:
- Traverse map
- Return elements whose count exceeds:

:contentReference[oaicite:2]{index=2}

# Complexity
- Time complexity:
  - `O(N)`

- Space complexity:
  - `O(N)`

# Code
```cpp
class Solution {

public:

    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> mp;

        vector<int> ans;

        int n = nums.size();

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {

            mp[nums[i]]++;
        }

        // Check majority elements
        for (auto ele : mp) {

            if (ele.second > n / 3) {

                ans.push_back(ele.first);
            }
        }

        return ans;
    }
};
```

---

# Approach 3: Optimal Boyer Moore Voting Algorithm

# Intuition
Since maximum 2 elements can appear more than:

:contentReference[oaicite:3]{index=3}

times,
we maintain:
- Two candidates
- Two counters

Main idea:
- Cancel out different elements
- Remaining candidates may become majority elements

Finally:
- Verify frequencies again

# Complexity
- Time complexity:
  - `O(N)`

- Space complexity:
  - `O(1)`

# Code
```cpp
class Solution {

public:

    vector<int> majorityElement(vector<int>& nums) {

        int cnt1 = 0;

        int cnt2 = 0;

        int ele1 = INT_MIN;

        int ele2 = INT_MIN;

        // Boyer Moore Voting
        for (auto num : nums) {

            if (cnt1 == 0 && num != ele2) {

                ele1 = num;

                cnt1 = 1;
            }

            else if (cnt2 == 0 && num != ele1) {

                ele2 = num;

                cnt2 = 1;
            }

            else if (num == ele1) {

                cnt1++;
            }

            else if (num == ele2) {

                cnt2++;
            }

            else {

                cnt1--;

                cnt2--;
            }
        }

        // Verify candidates
        cnt1 = 0;

        cnt2 = 0;

        for (auto num : nums) {

            if (num == ele1)
                cnt1++;

            else if (num == ele2)
                cnt2++;
        }

        vector<int> ans;

        if (cnt1 > nums.size() / 3)
            ans.push_back(ele1);

        if (cnt2 > nums.size() / 3)
            ans.push_back(ele2);

        return ans;
    }
};
```