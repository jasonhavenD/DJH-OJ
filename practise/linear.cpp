#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

#define True 1
#define False 1


typedef struct Node {
    int data;
    struct Node *next;
} Node;

/*******************括号匹配******************/
int kuoHaoMatch(char *s) {
    char *c = s;
    stack<char> st;
    while (*c != '\0') {//直接使用指针c进行遍历字符串s,c语言字符串的末尾是一个'\0'

        if (*c == '(' || *c == '[' || *c == '{') {//左括号入栈
            st.push(*c);//左括号入栈
        } else if (*c == ')' || *c == ']' || *c == '}') {//右括号
            if (st.empty())return False;//栈空了，说明栈中左括号没了，则不匹配，返回False
            char tc = st.top();//弹栈，弹出左括号
            st.pop();
            if ((tc == '(' && *c != ')') || (tc == '[' && *c != ']') || (tc == '{' && *c != '}'))
                return False;//判断弹出的左括号和当前的右括号是不是一对，不是则返回False
        }
        c++;//继续遍历下一个字符
    }
    if (st.empty())return False;//如果循环结束栈不为空，说明括号不是一对一对的，返回False
    return True;
}

/*******************两个栈实现队列******************/
stack<int> st1, st2;

void EnQueue(int val) {
    st1.push(val);
}

int DeQueue() {
    if (st2.empty()) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    int ans = st2.top();
    st2.pop();
    return ans;
}

/*******************两个队列实现栈******************/
queue<int> q1, q2;

void push(int val) {
    if (q2.empty())//如果q2为空，不管q1是不是为空都入队到q1
        q1.push(val);
    else
        q2.push(val);
}

int pop() {
    int ans;
    if (!q1.empty()) {//把q1队列中的元素都倒腾到q2，直到剩下一个元素
        while (q1.size() > 1) {
            q2.push(q1.front());//将队列1中的元素一个一个入队到队列2，直到队列1中剩余一个元素
            q1.pop();
        }
        ans = q1.back();
        q1.pop();
    } else {
        while (q2.size() > 1) {//把q2队列中的元素都倒腾到q1，直到剩下一个元素
            q1.push(q2.front());//将队列2中的元素一个一个入队到队列1，直到队列2中剩余一个元素
            q2.pop();
        }
        ans = q2.back();
        q2.pop();
    }
    return ans;
}

/*******************后缀表达式计算******************/
double caculate(char ch, double x, double y) {
    switch (ch) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            return 0;
    }
}

void postfixCaculate(char *s) {
    double ans = 0;//最终结果
    char *c = s;//迭代器
    stack<double> numsk;//操作数栈

    while (*c != '\0') {
        if (*c == '+' || *c == '-' || *c == '*' || *c == '/') {//运算符
            double y = numsk.top();
            numsk.pop();
            double x = numsk.top();
            numsk.pop();
            ans = caculate(*c, x, y);
            numsk.push(ans);
        } else {
            numsk.push(*c - '0');//操作数入栈
        }
        c++;
    }
    printf("%.2f", numsk.top());
}


/*******************单向链表中倒数第k个结点******************/
/* 两个指针first,second
 * 首先second不走，first走k步
 * 然后保持距离平移，一起走
 * first走到尾部时，second所在位置就是倒数第k个节点
 *  * */
Node *findBackKth(Node *head, int k) {
    Node *first, *second;
    first = second = head;
    int i = 0;
    while (i < k) {
        first = first->next;//first走k步
    }
    while (first != NULL) {//一起走
        first = first->next;
        second = second->next;
    }//first走到末尾
    return second;//second就是倒数第k个节点
}

/*
 *
首先，关于单链表中的环，一般涉及到一下问题：
1.给一个单链表，判断其中是否有环的存在；
2.如果存在环，找出环的入口点；
3.如果存在环，求出环上节点的个数；
4.（扩展）如何判断两个无环链表是否相交；
* */

/*******************1.链表是否有环******************/
/*使用快慢指针的方法*/
int hasCircle(Node *head) {
    Node *fast, *slow;
    slow = fast = head;
    while (slow != NULL && fast->next != NULL) {//没有环一定会结束循环
        slow = slow->next;//更新1步
        fast = fast->next->next;//更新2步
        if (slow == fast)//有环一定会追上
            return True;
    }
    return False;
}


/*******************2.环的入口点******************/
/*核心思想：快慢指针相遇的位置到环入口点的距离 == 环入口位置到头部的距离*/
Node *findCircleStart(Node *head) {
    Node *fast, *slow;
    slow = fast = head;

    while (slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }//如果有环则找到相遇的位置

    if (slow == NULL || fast->next == NULL) return NULL; //没有环，返回NULL值

    Node *ptr1 = head; //从开始点朝入口点走
    Node *ptr2 = slow; //从相遇位置朝入口点走
    while (ptr1 != ptr2) {//直到两者走到同一位置
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1; //找到入口点
}

/*******************3.环中节点个数******************/
/*找到相遇节点后，slow指针继续走，直到再次经过相遇点，走过的长度就是环长*/
int CircleNumbers(Node *head) {
    Node *fast, *slow;
    slow = fast = head;

    while (slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }//如果有环则找到相遇的位置

    if (slow == NULL || fast->next == NULL) return NULL; //没有环，返回NULL值
    Node *p = slow->next;
    int count = 1;
    while (p != slow) {
        p = p->next;
        count++;
    }
    return count;
}


/*******************4.判断两个无环链表是否相交******************/
/*
 * 有两种可取的办法：
（1）人为构环，将链表A的尾节点指向链表B，再判断是否构环成功？从链表B的头指针往下遍历，如果能够回到B，则说明相交
（2）判断两链表最后一个节点是否相同，如果相交，则尾节点肯定是同一节点
 * */
int isInteractive1(Node *h1, Node *h2) {//第一种方法
    Node *p = h1;
    while (p->next != NULL)p = p->next;
    p->next = h2;//把尾巴链接到B链表
    return hasCircle(h1);//判断是否有环
}


int isInteractive2(Node *h1, Node *h2) {//第二种方法
    Node *p = h1;
    Node *q = h2;
    while (p->next != NULL)p = p->next;
    while (q->next != NULL)q = q->next;
    return p == q;
}

/*******************5.两个链表的第一个公共结点******************/
/*
 * 如果两个链表相交，一定表现为字母“Y”的形状，刚开始是分开的，后面是重合的
 * 第一个相交的节点就是目标节点
 * 两个链表长度不一样，假设长度差距为d
 * 在长链表上遍历d个位置，就是第一个相交的节点
 * */
Node *firstCommonNode(Node *h1, Node *h2) {
    //首先两个链表是否相交，如果不相交则没有公共节点
    Node *p = h1;
    Node *q = h2;
    int len1 = 0, len2 = 0;
    while (p->next != NULL) {
        p = p->next;
        len1++;
    }
    while (q->next != NULL) {
        q = q->next;
        len2++;
    }
    if (len1 > len2) {//在长链表上遍历
        int d = len1 - len2;//差距为d
        p = h1;
        while (p != NULL && d > 0) {
            p = p->next;
            d--;
        }
        return p;
    } else {//在长链表上遍历
        int d = len2 - len1;//差距为d
        p = h2;
        while (p != NULL && d > 0) {
            p = p->next;
            d--;
        }
        return p;
    }
}
