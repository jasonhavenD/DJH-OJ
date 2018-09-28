class Solution:
    def is_palindromic(self,s): 
        if len(s)==1:
            return True
        rs=s[::-1]
        return rs==s
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt=0
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if self.is_palindromic(s[i:j]):
                    cnt+=1
        return cnt
        
        