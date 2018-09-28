class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        rst=[]
        for x in range(n):
            x=x+1
            if x%15==0:
                rst.append("FizzBuzz")
            elif x%3==0:
                rst.append("Fizz")
            elif x%5==0:
                rst.append("Buzz")
            else:
                rst.append(str(x))
        return rst
        