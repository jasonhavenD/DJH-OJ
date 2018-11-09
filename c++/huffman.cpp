//
// 哈弗曼树
// 构建哈夫曼树时，需要每次根据各个结点的权重值，筛选出其中值最小的两个结点，然后构建二叉树。
// http://data.biancheng.net/view/33.html
// Created by jasonhaven on 18-11-8.
//

/*
对于同一组权值，所能得到的赫夫曼树不一定是唯一的。
赫夫曼树的左右子树可以互换，因为这并不影响树的带权路径长度。
带权值的节点都是叶子节点，不带权值的节点都是某棵子二叉树的根节点。
权值越大的节点越靠近赫夫曼树的根节点，权值越小的节点越远离赫夫曼树的根节点。
赫夫曼树中只有叶子节点和度为2的节点，没有度为1的节点。
一棵有n个叶子节点的赫夫曼树共有2n-1个节点。
 * */

#include <bits/stdc++.h>

typedef struct {
    int weight;//结点权重
    int parent, left, right;//父结点、左孩子、右孩子在数组中的位置下标
} HNode, *HTree;

//动态二维数组，存储哈夫曼编码
typedef char **HCode;


void SelectTwoNodes(HTree HT, int end, int *s1, int *s2) {
    /*
     * hTree 数组中存放的哈夫曼树[1,end],
     * end 表示HT数组中存放结点的最终位置，
     * s1和s2 传递的是HT数组中权重值最小的两个结点在数组中的位置
     *
     * 查找权重值最小的两个结点的思想是：
            从树组起始位置开始，首先找到两个无父结点的结点（说明还未使用其构建成树），然后和后续无父结点的结点依次做比较，
        有两种情况需要考虑：
            如果比两个结点中较小的那个还小，就保留这个结点，删除原来较大的结点；
            如果介于两个结点权重值之间，替换原来较大的结点；
     */
    int min1, min2;
    int i = 1;
    while (HT[i].parent != 0 && i <= end) { i++; }//找到还没有构建成树的节点（无父节点的节点）

    *s1 = i;//记录下标
    min1 = HT[i].weight;//记录权重

    i++;
    while (HT[i].parent != 0 && i <= end) { i++; }//继续找下一个没有构建成树的节点

    *s2 = i;//记录下标
    min2 = HT[i].weight;//记录权重

    if (min2 < min1) {//对找到的两个结点比较大小，min2为较大的，min1为较小的
        int t = min1;
        min2 = min1;
        min1 = t;

        *s2 = *s1;
        *s1 = i;
    }

    for (int j = i + 1; j <= end; j++) {//两个结点和后续的所有未构建成树的结点做比较
        if (HT[j].parent != 0)continue;
        if (HT[j].weight < min1) {//如果比min1还小，将min2=min1，min1赋值新的结点的下标
            min2 = min1;
            *s2 = *s1;
            min1 = HT[j].weight;
            *s1 = j;
        } else if (HT[j].weight < min2) {//如果介于两者之间，min2赋值为新的结点的位置下标
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}


void CreateHuffmanTree(HTree *HT, int *w, int n) {
    /*
     * HT 哈弗曼树的数组[1,m]
     * w 权重数组[0,n-1]
     * n 待编码节点个数（叶子节点）
     *
     * */
    if (n <= 1)return;
    int m = 2 * n - 1;
    *HT = (HTree) malloc((m + 1) * sizeof(HNode));//0位置不用

    HTree p = *HT;
    int i;

    //初始化哈夫曼树中的n个叶子结点
    for (i = 1; i <= n; i++) {
        (p + i)->weight = w[i - 1];
        (p + i)->parent = 0;
        (p + i)->left = 0;
        (p + i)->right = 0;
    }
    //从树组的下标 n+1 开始初始化哈夫曼树中除叶子结点外的结点
    for (i = n + 1; i <= m; i++) {
        (p + i)->weight = 0;
        (p + i)->parent = 0;
        (p + i)->left = 0;
        (p + i)->right = 0;
    }
    //构建哈夫曼树
    for (i = n + 1; i <= m; i++) {
        int s1, s2;
        SelectTwoNodes(*HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}


//HT为哈夫曼树，HC为存储结点哈夫曼编码的二维动态数组，n为结点的个数
void HuffmanCoding(HTree HT, HCode *HC, int n) {
    *HC = (HCode) malloc((n + 1) * sizeof(char *));
    char *cd = (char *) malloc(n * sizeof(char)); //存放结点哈夫曼编码的字符串数组
    cd[n - 1] = '\0';//字符串结束符

    for (int i = 1; i <= n; i++) {
        //从叶子结点出发，得到的哈夫曼编码是逆序的，需要在字符串数组中逆序存放
        int start = n - 1;
        //当前结点在数组中的位置
        int c = i;
        //当前结点的父结点在数组中的位置
        int j = HT[i].parent;
        // 一直寻找到根结点
        while (j != 0) {
            // 如果该结点是父结点的左孩子则对应路径编码为0，否则为右孩子编码为1
            if (HT[j].left == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            //以父结点为孩子结点，继续朝树根的方向遍历
            c = j;
            j = HT[j].parent;
        }
        //跳出循环后，cd数组中从下标 start 开始，存放的就是该结点的哈夫曼编码
        (*HC)[i] = (char *) malloc((n - start) * sizeof(char));
        strcpy((*HC)[i], &cd[start]);
    }
    //使用malloc申请的cd动态数组需要手动释放
    free(cd);
}

//打印哈夫曼编码的函数
void PrintHuffmanCode(HCode htable, int *w, int n) {
    printf("Huffman code : \n");
    for (int i = 1; i <= n; i++)
        printf("%d code = %s\n", w[i - 1], htable[i]);
}

int main(void) {
    int w[5] = {2, 8, 7, 6, 5};
    int n = 5;
    HTree htree;
    HCode htable;
    CreateHuffmanTree(&htree, w, n);
    HuffmanCoding(htree, &htable, n);
    PrintHuffmanCode(htable, w, n);
    return 0;
}