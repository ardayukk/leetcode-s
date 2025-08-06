class Solution:
    def maxArea(self, height: List[int]) -> int:
        max = 0
        low = 0
        high = len(height) - 1
        while(low < high):
            if (high - low) * min(height[low],height[high]) > max:
                max = (high - low) * min(height[low],height[high])
            if height[low] > height[high]:
                high -= 1
            else:
                low += 1
        return max