class Solution:
    def trap(self, height: List[int]) -> int:
        sum = 0
        lowIndex = 0 
        leftMax = height[0]
        highIndex = len(height) - 1
        rightMax = height[highIndex]
        while lowIndex < highIndex:
            if leftMax <= rightMax:
                sum += leftMax - height[lowIndex]
                lowIndex += 1
                leftMax = max(leftMax, height[lowIndex])
            else:
                sum += rightMax - height[highIndex]
                highIndex -= 1
                rightMax = max(rightMax, height[highIndex])
        return sum