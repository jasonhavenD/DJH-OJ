class Solution:
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        rs=list(ransomNote)
        ms=list(magazine)
        for r in rs:
            if r not in ms:
                return False
            else:
                ms.remove(r)
        return True