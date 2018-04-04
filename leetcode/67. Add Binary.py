class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a=int('0b'+a,2)
        b=int('0b'+b,2)
        return bin(a+b)[2:]
        