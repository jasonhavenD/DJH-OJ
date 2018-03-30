class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        table=["qwertyuiop","asdfghjkl","zxcvbnm"]
        rst=[]
        for i,word in  enumerate([w.lower() for w in words]):
            count=[0,0,0]
            for w in word:
                if w in table[0]:
                    count[0]+=1
                elif w in table[1]:
                    count[1]+=1
                elif w in table[2]:
                    count[2]+=1
            if len(word) in count:
                rst.append(words[i])
        return rst
                

        