//
// Created by jasonhaven on 18-11-6.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct lineStack {
    char data;
    struct lineStack *next;
} lineStack;

lineStack *push(lineStack *stack, char a) {
    lineStack *line = (lineStack *) malloc(sizeof(lineStack));
    line->data = a;
    line->next = stack;
    stack = line;
    return stack;
}

lineStack *pop(lineStack *stack) {
    if (stack) {
        lineStack *p = stack;
        stack = stack->next;
        printf("弹栈元素：%c ", p->data);
        if (stack) {
            printf("栈顶元素：%c\n", stack->data);
        } else {
            printf("栈已空\n");
        }
        free(p);
    } else {
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}
/*
int main() {
    lineStack *stack = NULL;
    stack = push(stack, 'a');
    stack = push(stack, 'b');
    stack = push(stack, 'c');
    stack = push(stack, 'd');
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    stack = pop(stack);
    return 0;
}*/