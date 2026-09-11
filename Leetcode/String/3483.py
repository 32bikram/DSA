class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        freq = [0]*10
        for x in digits:
            freq[x] += 1

        ans = 0
        for i in range(10):
            if i == 0:
                continue
            temp = freq.copy()
            if temp[i] == 0:
                continue
            temp[i] -= 1
            for j in range(10):
                if temp[j] == 0:
                    continue
                temp[j] -= 1
                for k in range(10):
                    if (temp[k] == 0):
                        continue
                    if k%2 != 0:
                        continue
                    ans += 1

                temp[j] += 1
            temp[i] += 1
        
        return ans
