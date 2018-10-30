#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define True 1
#define False 1


void show(int *a, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void show(int **a, int n, int m) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*******************动态数组创建和销毁******************/
void dynamicArray() {
    //void *malloc( size_t size ); //分配的大小
    //void *calloc( size_t numElements, size_t sizeOfElement ); // 分配元素的个数和每个元素的大小
    //malloc 不会初始化内存
    //calloc 会初始化内存
    int *a1, *a2;
    int n1 = 10, n2 = 10;
    a1 = (int *) calloc(n1, sizeof(int));//推荐使用calloc
    a2 = (int *) malloc(n2 * sizeof(int));

    show(a1, n1);
    show(a2, n2);

    free(a1);//释放一维指针
    free(a2);//释放一维指针
}

/*******************动态矩阵创建和销毁******************/
void dynamicMatrix() {
    int **a;
    int n = 3, m = 4;
    int i;
    a = (int **) calloc(n, sizeof(int));
    for (i = 0; i < n; ++i) {
        a[i] = (int *) calloc(m, sizeof(int));
    }
    show(a, n, m);
    for (i = 0; i < n; i++) {
        free(a[i]);//释放第二维指针
    }
    free(a);//释放第一维指针
}

/*******************静态数组******************/
void staticArray() {
    int n = 5;
    int a[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    show(a, n);
}

/*******************静态矩阵******************/
void staticMatrix() {
    int n = 5, m = 3;
    int a[n][m];
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


/*******************矩阵加法******************/
void matrixAdd() {
    const int n1 = 2, m1 = 3, n2 = 2, m2 = 3;
    int ans[n1][m1];
    int i, j;
    int c1[n1][m1] = {//2*3
            {1, 1, 1},
            {1, 1, 1},
    };
    int c2[n2][m2] = {//3*2
            {2, 2, 2},
            {2, 2, 2},
    };
    if (n1 == n2 && m1 == m2) {//首先判断矩阵是否是同型矩阵
        for (i = 0; i < n1; ++i) {
            for (j = 0; j < m1; ++j) {
                ans[i][j] = c1[i][j] + c2[i][j];//相同位置相加
            }
        }
    }
    for (i = 0; i < n1; ++i) {
        for (j = 0; j < m1; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

/*******************矩阵减法******************/
void matrixMinus() {
    const int n1 = 2, m1 = 3, n2 = 2, m2 = 3;
    int ans[n1][m1];
    int i, j;
    int c1[n1][m1] = {//2*3
            {1, 1, 1},
            {1, 1, 1},
    };
    int c2[n2][m2] = {//3*2
            {2, 2, 2},
            {2, 2, 2},
    };
    if (n1 == n2 && m1 == m2) {//首先判断矩阵是否是同型矩阵
        for (i = 0; i < n1; ++i) {
            for (j = 0; j < m1; ++j) {
                ans[i][j] = c1[i][j] - c2[i][j];//相同位置相减
            }
        }
    }
    for (i = 0; i < n1; ++i) {
        for (j = 0; j < m1; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

/*******************矩阵×矩阵******************/
void matrixMultiply() {
    const int n1 = 2, m1 = 3;
    const int n2 = 3, m2 = 4;
    int i, j, k;
    int ans[n1][m2] = {0};
    int c1[n1][m1] = {//2*3
            {1, 1, 1},
            {1, 1, 1},
    };
    int c2[n2][m2] = {//3*4
            {2, 2, 2, 2},
            {2, 2, 2, 2},
            {2, 2, 2, 2},
    };
    if (m1 == n2) {//首先判断是否满足乘法规则
        for (i = 0; i < n1; ++i) {//控制行
            for (j = 0; j < m2; ++j) {//控制列
                for (k = 0; k < m1; ++k) {
                    ans[i][j] += c1[i][k] * c2[k][j];//行×列的和==结果的一个元素
                }
            }
        }
    }
    for (i = 0; i < n1; ++i) {
        for (j = 0; j < m1; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

/*******************向量×矩阵******************/
void vectorDotMatrix() {
    int a[3] = {1, 2, 3};
    int c1[3][2] = {
            {1, 1},
            {1, 1},
            {1, 1},
    };
    int i, j;
    int ans[2] = {0};//注意size

    for (j = 0; j < 2; ++j) {//控制列
        for (i = 0; i < 3; ++i) {//向量计算
            ans[j] += a[i] * c1[i][j];//注意下标
        }
    }
    show(ans, 2);//[6,6]
}


/*******************向量×向量******************/
void vectorDotvector() {
    int a[3] = {1, 2, 3};
    int b[3][1] = {{4},
                   {5},
                   {6}};
    int ans = 0;//1*3  3*1 -> 1
    int i;
    for (i = 0; i < 3; ++i) {
        ans += a[i] * b[i][0];
    }
    printf("%d", ans);//32


}

/*******************对称矩阵******************/
int isSymmetry() {
    int n = 3;
    int a[3][3] = {
            {1, 2, 3},
            {2, 2, 3},
            {3, 3, 3}
    };
    int flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                flag = false;//只要出现对称的位置不相等则跳出循环，不是对称矩阵
                break;
            }
        }
    }
    if (flag)printf("Yes!\n");//ok
    else printf("No!\n");
}

/*******************顺时针打印矩阵******************/
// https://blog.csdn.net/a_little_snail/article/details/69264541

int main() {
//    dynamicArray();
//    dynamicMatrix();
//    staticArray();
//    staticMatrix();
//    matrixMultiply();
//    vectorDotMatrix();
//    vectorDotvector();
    isSymmetry();
    return 0;
}
