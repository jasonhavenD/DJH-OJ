class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        lst=re.findall(r'\w+',s)
        s=''.join([c.lower() for c in lst])
        rs=s[::-1]
        return rs==s