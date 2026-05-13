class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) // O(n) solution
    {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;
        int l = 0, r = 0;

        while (r < n)
        {
            while (!dq.empty() && nums[dq.back()] < nums[r])
            {
                dq.pop_back();
            }
            dq.push_back(r);

            if (l > dq.front())
            {
                dq.pop_front();
            }

            if (r + 1 >= k)
            {
                res.push_back(nums[dq.front()]);
                l += 1;
            }
            r += 1;
        }
        return res;
    }
};
