#include <stdio.h>

#define True 1
#define False 1


void swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

/*******************冒泡排序******************/
void Bubble(int *a, int n) {//冒泡排序
    int i, j;
    for (i = 0; i < n; i++) {//循环次数
        for (j = n - 1; j > i; j--) {//从后向前
            if (a[j] < a[j - 1]) {//前者大于后者，则交换
                swap(a, j, j - 1);
            }
        }
    }
}

void Bubble2(int *a, int n) {//冒泡排序改进版本
    int i, j;
    int flag = True;//控制循环的开关
    for (i = 0; i < n && flag; i++) {
        flag = False;//每一轮循环的初始化
        for (j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a, j, j - 1);
                flag = True;//如果存在交换则更新开关为True，如果没有交换也就意味着flag==False，说明后面的序列是有序的，停止循环
            }
        }
    }
}

/*******************选择排序******************/
void Select(int *a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int min = i;//初始化当前待排序位置为 i
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a, i, min);//交换最小值所在位置min和当前位置i
    }
}

/*******************插入排序******************/
void Insert(int *a, int n) {//将无序元素插入到有序序列中
    int i, j;
    for (i = 1; i < n; i++) {//默认第一个元素是已排好序的元素，从第二个元素开始i==1
        int temp = a[i];//待排序元素temp
        for (j = i - 1; j >= 0; j--) {//在[0,i-1]有序序列中找位置
            if (temp < a[j]) {//循环向后移动元素，直到找到位置
                a[j + 1] = a[j];
            } else {
                break;//找到位置就跳出循环
            }
        }
        a[j + 1] = temp;//将待排序元素赋值到最终位置
    }
}

/*******************归并排序******************/
void Merge(int *a, int start, int mid, int last, int *temp) {
    int index = 0;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= last) {
        if (a[i] >= a[j]) {
            temp[index++] = a[j++];
        } else {
            temp[index++] = a[i++];
        }
    }

    while (i <= mid) {
        temp[index++] = a[i++];
    }
    while (j <= last) {
        temp[index++] = a[j++];
    }

    for (i = 0; i < index; i++) {
        a[start + i] = temp[i];
    }
}


void MergeSort(int *a, int left, int right, int *temp) {
    int mid = (left + right) / 2;
    if (left < right) {
        //使数组的左边有序
        MergeSort(a, left, mid, temp);
        //使数组的右边有序
        MergeSort(a, mid + 1, right, temp);
        //合并数组
        Merge(a, left, mid, right, temp);
    }

}

/*******************快速排序******************/
int partition(int *a, int left, int right) {
    int i = left;
    int j = right;
    int pivotVal = a[left];
    while (i < j) {
        while (i < j && pivotVal <= a[j])j--;
        swap(a, i, j);
        while (i < j && pivotVal >= a[i])i++;
        swap(a, i, j);
    }
    a[i] = pivotVal;
    return i;

}

void Quick(int *a, int left, int right) {
    if (left < right) {
        int pivot = partition(a, left, right);//找到pivot
        Quick(a, left, pivot - 1);
        Quick(a, pivot + 1, right);
    }
}


void Quick2(int *a, int left, int right)//将划分和排序合并到一个方法
{
    int i = left;                                    //寻找比“标准数”小时左边遍历的下标(左哨兵)
    int j = right;                                    //寻找比“标准数”大的右遍历下的标(右哨兵)
    int pivotVal = a[left];                          //存储"标准数"用于后面的交换
    while (i < j) {
        while (i < j && pivotVal <= a[j])j--;
        swap(a, i, j);
        while (i < j && pivotVal >= a[i])i++;
        swap(a, i, j);
    }
    a[i] = pivotVal;//此时i就是pivot
    Quick2(a, left, i - 1);                     //递归处理左边的数组
    Quick2(a, i + 1, right);                     //递归处理右边的数组
}


/*******************堆排序******************/
void HeapAdjust(int a[], int i, int n) {
    int nChild, nTemp;
    for (nTemp = a[i]; 2 * i + 1 < n; i = nChild) {
        // nChild:左子结点的位置是 父结点位置 * 2 + 1  nChild + 1： 右子结点
        nChild = 2 * i + 1;
        // 得到子结点中较大的结点
        if (nChild != n - 1 && a[nChild + 1] > a[nChild])
            ++nChild;
        // 如果较大的子结点大于父结点那么把较大的子结点往上移动,替换它的父结点
        if (nTemp < a[nChild]) {
            a[i] = a[nChild];
        } else  // 否则退出循环
        {
            break;
        }
    }
    // 最后把需要调整的元素值放到合适的位置
    a[i] = nTemp;
}

// 堆排序算法
void HeapSort(int a[], int n) {
    // 调整序列的前半部分元素,（即每个有孩子的节点）调整完之后是一个大顶堆，第一个元素是序列的最大的元素
    for (int i = n / 2 - 1; i >= 0; --i) {
        HeapAdjust(a, i, n);
    }
    // 从最后一个元素开始对序列进行调整,不断的缩小调整的范围直到第一个元素
    for (int i = n - 1; i > 0; --i) {
        // 把第一个元素和当前的最后一个元素交换,
        // 保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        swap(a, 0, i);
        // 不断缩小调整heap的范围,每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(a, 0, i);
    }
}


void Show(int *a, int n)// 打印结果
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}


int main() {
    int n;
    int a[n];
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);// 0 2 3 1 4 6 5 8 7 9
    }
//    Bubble(a, n);
//    Bubble2(a, n);
//    Select(a, n);
//    Insert(a, n);

//    int tmp[n];
//    MergeSort(a,0,n-1,tmp);

//    Quick(a, 0, n - 1);
//    Quick2(a, 0, n - 1);

    HeapSort(a, n);
    Show(a, n);
    return 0;
}