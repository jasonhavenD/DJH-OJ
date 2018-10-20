#include <stdio.h>

#define True 1
#define False 1


void swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}


void Show(int *a, int n)// 打印结果
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

/*******************计数排序******************/
void Counting(int *a, int n) {
    //稳定的线性复杂度排序算法,空间换时间
    //第一步确定数组值的范围[0,max]
    if (n < 0)return;
    int max = a[0];
    int i, j;
    for (i = 1; i < n; ++i) {
        if (a[i] > max)max = a[i];
    }
    //第二步声明查找数组并初始化为0
    int table[max + 1];
    for (i = 0; i <= max; ++i) {
        table[i] = 0;
    }
    //排序
    for (i = 0; i < n; ++i) {
        table[a[i]] += 1;
    }
    //打印排序结果
    for (i = 0; i <= max; ++i) {
        for (j = 0; j < table[i]; ++j) {
            printf("%d", i);
        }
    }
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


// https://www.cnblogs.com/chengxiao/p/6129630.html
//堆排序是一种选择排序，它的最坏，最好，平均时间复杂度均为O(nlogn)，它也是不稳定排序
//堆是具有以下性质的完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆
/*******************堆排序2******************/
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heapify(int arr[], int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;//左孩子 son+1==右孩子
    while (son <= end) { //若子节点指标在范围内才做比较，这里是一个循环调整，保证从start到end满足大顶堆
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;//最大的son
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(&arr[dad], &arr[son]);//父节点和子节点交换  //此处也可以使用Swap(a,dad,son)
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    //构建初始堆+交换堆顶元素和末尾元素并重建堆  两部分组成
    int i;

    //构建初始堆
    for (i = len / 2 - 1; i >= 0; i--)//从最后一个非叶子节点开始，从左到右，从下到上
        max_heapify(arr, i, len - 1);//调整i到len-1的堆

    //交换堆顶元素和末尾元素并重建堆
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);//将大顶堆堆顶元素与末尾元素交换
        max_heapify(arr, 0, i - 1);//将剩余元素重新构造成一个堆，继续选择次小值
    }
}

//int main() {
//    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
//    int len = (int) sizeof(arr) / sizeof(*arr);
//    heap_sort(arr, len);
//    int i;
//    for (i = 0; i < len; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    return 0;
//}
/*******************堆排序2******************/


//int main() {
//    int i;
//    int a[5];
//    for (i = 0; i < 5; i++) {
//        scanf("%d", &a[i]);// 0 2 3 1 4 6 5 8 7 9
//    }
//    Counting(a, 5);
//    return 0;
//}
//
//int main() {
//    int n;
//    int a[n];
//    int i, j;
//    scanf("%d", &n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &a[i]);// 0 2 3 1 4 6 5 8 7 9
//    }
////    Bubble(a, n);
////    Bubble2(a, n);
////    Select(a, n);
////    Insert(a, n);
//
////    int tmp[n];
////    MergeSort(a,0,n-1,tmp);
//
////    Quick(a, 0, n - 1);
////    Quick2(a, 0, n - 1);
//
////    HeapSort(a, n);
//    Show(a, n);
//    return 0;
//}