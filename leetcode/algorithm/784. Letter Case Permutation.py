class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        ans = []

        def dfs(S, pos, str):
            if pos == len(S):
                ans.append(str)
                return
            else:
                if S[pos].isalpha():
                    letter = S[pos]
                    dfs(S, pos + 1, str + letter.upper())
                    dfs(S, pos + 1, str + letter.lower())
                else:
                    dfs(S, pos + 1, str + S[pos])
        dfs(S, 0, '')
        return ans[::-1]
        