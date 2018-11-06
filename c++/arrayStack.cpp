//
// Created by jasonhaven on 18-11-6.
//

#include <stdio.h>

//元素elem进栈
int push(char *a, int top, char elem) {
    a[++top] = elem;
    return top;
}

//数据元素出栈
int pop(char *a, int top) {
    if (top == -1) {
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%c\n", a[top]);
    top--;
    return top;
}
/*
int main() {
    char a[100];
    int top = -1;
    top = push(a, top, 'a');
    top = push(a, top, 'b');
    top = push(a, top, 'c');
    top = push(a, top, 'd');
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);
    return 0;
}*/