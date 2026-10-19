class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        count, length = 0, 0
        for i, num in enumerate(nums):
            if(nums[i]<target):
                count += 1
            elif(nums[i]==target):
                length += 1
        ans = []
        while(length>0):
            ans.append(count)
            count += 1
            length -= 1
        return ans
