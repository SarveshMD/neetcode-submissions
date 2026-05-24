class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums_combined = []
        n = len(nums1)
        m = len(nums2)
        i = j = k = 0
        m_n = n+m
        while (i < n and j < m and k <= m_n//2):
            if (nums1[i] <= nums2[j]):
                nums_combined.append(nums1[i])
                i+=1
            else:
                nums_combined.append(nums2[j])
                j+=1
            k += 1
        while (i < n and k <= m_n//2):
            nums_combined.append(nums1[i])
            i += 1
            k += 1
        while (j < m and k <= m_n//2):
            nums_combined.append(nums2[j])
            j += 1
            k += 1
        if (m_n % 2 == 0):
            return (nums_combined[m_n//2] + nums_combined[m_n//2-1])/2
        else:
            return nums_combined[m_n//2]
