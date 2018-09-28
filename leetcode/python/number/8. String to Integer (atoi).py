class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str=str.strip()
        if len(str)==0:
            return 0
        try:
            res = re.search('(^[\+\-]?\d+)', str).group()
            res=max(-2**31, min(int(res),2**31-1))
        except:
            res = 0
        return res