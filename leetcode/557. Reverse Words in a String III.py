class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join(s[::-1] for s in s.split())
        
        