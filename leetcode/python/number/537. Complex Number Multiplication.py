class Solution:
    def complexNumberMultiply(self, c1, c2):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a,b=c1.split('+')
        c,d=c2.split('+')
        a=int(a)
        b=int(b[:-1])
        c=int(c)
        d=int(d[:-1])
        return "{}+{}i".format(a*c-b*d,b*c+a*d)