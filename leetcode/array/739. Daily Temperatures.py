¡®¡¯¡®
Time Limit Exceeded

¡¯¡®¡¯
class Solution:
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        rst=[0]*len(temperatures)
        for i,x in enumerate(temperatures):
            flag=False
            
            if i == len(temperatures)-1:
                rst[i]=0
                break
                
            for j,y in enumerate(temperatures[i+1:]):
                if flag==False and y>x:
                    rst[i]=j+1
                    flag=True
                    break
            if flag == False:
                rst[i]=0

        return rst




¡®¡¯¡®
Accepted

¡¯¡®¡¯

class Solution:
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        n = len(temperatures)
        stack = []
        rst = [0] * n

        for i in range(n):
            while (len(stack) > 0 and temperatures[stack[-1]] < temperatures[i]):
                nxt = stack.pop(-1)
                rst[nxt] = i - nxt
            stack.append(i)
        return rst
