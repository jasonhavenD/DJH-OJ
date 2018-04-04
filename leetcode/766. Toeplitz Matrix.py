class Solution(object):
    def isToeplitzMatrix(self,matrix):
        M=len(matrix)
        N=len(matrix[0])
        for i in range(M-1):#M-1->0
            for j in range(N-1):#0->N-1
                if matrix[i][j]!=matrix[i+1][j+1]:
                    return False
        return True
    