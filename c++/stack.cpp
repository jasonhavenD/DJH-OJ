#include <stdio.h>
#include <malloc.h>


typedef int E;

/*******************链栈*****************/
struct node {
    E data;
    struct node *next;
};
typedef struct node Node;


Node *Create(Node *head, int n) {
    int i;
    E x;
    Node *p = head;
    for (i = 0; i < n; i++) {
        Node *t;
        scanf("%d", &x);
        t = (Node *) malloc(sizeof(Node));
        t->data = x;
        //头插法
        t->next = p->next;
        p->next = t;
    }
    return head;
}

void Tranverse(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void destory(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        Node *t;
        t = p;
        p = p->next;
        free(t);
    }
    free(head);
}


void Push(Node *head, Node *node) {//头插法
    node->next = head->next;
    head->next = node;
}

Node *Pop(Node *head) {//头删法
    Node *p = head->next;
    if (p->next) {
        Node *tmp = head;
        head = p->next;
        free(tmp);
    }
    return p;
}

/*******************顺序栈*****************/
/* 数组实现
 * 数组顶端top指针
 * */

int main() {
    Node *head;
    head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    head = Create(head, 3);
    Tranverse(head);
    Node *t = Pop(head);
    printf("Pop=%d\n", t->data);
    t = (Node *) malloc(sizeof(Node));
    t->data = 9;
    t->next = NULL;
    Push(head, t);
    Tranverse(head);
    free(t);
    return 0;
}