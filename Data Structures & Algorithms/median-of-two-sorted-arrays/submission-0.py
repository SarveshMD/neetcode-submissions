class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums_combined = []
        n = len(nums1)
        m = len(nums2)
        i = j = 0
        while (i < n and j < m):
            if (nums1[i] <= nums2[j]):
                nums_combined.append(nums1[i])
                i+=1
            else:
                nums_combined.append(nums2[j])
                j+=1
        while (i < n):
            nums_combined.append(nums1[i])
            i += 1
        while (j < m):
            nums_combined.append(nums2[j])
            j += 1
        m_n = n+m
        if (m_n % 2 == 0):
            return (nums_combined[m_n//2] + nums_combined[m_n//2-1])/2
        else:
            return nums_combined[m_n//2]
