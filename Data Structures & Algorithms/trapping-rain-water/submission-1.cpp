class Solution {
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxL = height[left], maxR = height[right];
        int totalStored = 0;
        while (left < right)
        {
            int bottleneck = min(maxL, maxR);
            if (maxL <= maxR)
            {
                int stored = max(0, bottleneck - height[left]);
                totalStored += stored;
                left++;
            }
            else
            {
                int stored = max(0, bottleneck - height[right]);
                totalStored += stored;
                right--;
            }
            maxL = max(maxL, height[left]), maxR = max(maxR, height[right]);
        }
        return totalStored;
    }
};
