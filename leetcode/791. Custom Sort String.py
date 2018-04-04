class Solution(object):
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        c, s = collections.Counter(T), set(S)
        return ''.join(i * c[i] for i in S) + ''.join(i * c[i] for i in c if i not in s)
        