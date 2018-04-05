class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        left=['{','[','(']
        right=['}',']',')']
        stack=[]
        for c in s:
            if c in left:
                stack.append(c)
            elif len(stack)==0:
                return False
            else:
                lc=stack.pop()
                if left.index(lc)!=right.index(c):
                    return False

        if len(stack)!=0:
            return False
        return True
        