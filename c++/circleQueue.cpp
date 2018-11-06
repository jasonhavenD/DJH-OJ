//
// 循环队列
//
// Created by jasonhaven on 18-11-6.
//


#include <stdio.h>

#define max 5

int enQueue(int *a, int front, int rear, int data) {
    //循环队列中，如果尾指针和头指针重合，证明数组存放的数据已满
    if ((rear + 1) % max == front) {
        printf("空间已满");
        return rear;
    }
    a[rear % max] = data;
    rear++;
    return rear;
}

int deQueue(int *a, int front, int rear) {
    //如果front==rear，表示队列为空
    if (front == rear) {
        printf("队列为空");
        return front;
    }
    printf("%d", a[front]);
    front = (front + 1) % max;
    return front;
}

int main() {
    int a[max];
    int front, rear;
    //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    //入队
    rear = enQueue(a, front, rear, 1);
    rear = enQueue(a, front, rear, 2);
    rear = enQueue(a, front, rear, 3);
    rear = enQueue(a, front, rear, 4);
    //出队
    front = deQueue(a, front, rear);

    rear = enQueue(a, front, rear, 5);

    front = deQueue(a, front, rear);
    rear = enQueue(a, front, rear, 6);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    return 0;
}