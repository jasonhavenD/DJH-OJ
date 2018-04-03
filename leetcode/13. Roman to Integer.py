class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        digits = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        sum = digits[s[len(s)-1]]
        for i in range(len(s)-1, 0, -1):
            cur = digits[s[i]]
            pre = digits[s[i-1]]
            sum += pre if pre >= cur else -pre
        return sum
        
        
        