#include <stdio.h>
#include <math.h>
#include <cstring>


#define True 1
#define False 0

/*
数字处理的编程概念

计算数字位数：(int)log10(x)+1)

简单-------素数（质数），合数(不是质数就是合数)，最小公倍数，最大公约数，最简分数，水仙花数（阿姆斯特朗数），完全数（盈数，亏数），回文数（对称数），回文质数
中等-------质因数，守形数，中位数
较难-------进制转换，丑数

*/

/*******************素数、质数******************/
int isPrime(int x) {
    int i;
    for (i = 2; i <= sqrt(x); ++i) {//[2,sqrt(x)]
        if (x % i == 0)break;//有因数则不是质数
    }
    return i > sqrt(x) ? True : False;
}

/*******************合数******************/
int isComposite(int x) {
    return isPrime(x) ? False : True;
}

/*******************数字反向******************/
//输入1234 得到4321
int reverseNumber1(int x) {
    int ans = 0;
    while (x != 0) {
        ans += x % 10;
        x /= 10;
        ans *= 10;
    }
    return ans / 10;
}

//输入1234 得到4321
int reverseNumber2(int x) {
    int i, r;
    int n = (int) log10(x) + 1;
    int ans = 0;
    for (i = 0; i < n; ++i) {
        r = x % 10;
        x /= 10;
        ans += r * pow(10, n - 1 - i);
    }
    return ans;
}

/*******************回文数******************/
int isPalin(int x) {
    int y = reverseNumber1(x);
    return x == y;
}


/*******************水仙花数(字幂数的一种，n==3),自恋数，阿姆斯特朗数，字幂数******************/
int isNarcissistic(int x) {//通用代码，字幂数
    int i;
    int n = (int) log10(x) + 1;//n位数
    int ans = 0;
    int oldx = x;
    while (x != 0) {
        ans += pow(x % 10, n);//每个位数的n次幂之和
        x /= 10;
    }
    return ans == oldx;
}

/*******************完数(完全数)盈数亏数******************/
void isFull(int x) {
    int i = 1;
    int sum = 0;
    while (i < x) {
        if (x % i == 0)sum += i;//真因子之和
        i++;
    }
    if (x == sum)printf("完数!\n");
    else if (x > sum)printf("亏数!\n");
    else if (x < sum)printf("盈数!\n");
}


/*******************最小公倍数******************/
int miniCommonMultiple(int x, int y) {
    if (x == 0 || y == 0)return 0;
    int r = 1;
    while (r) {//辗转相除法
        r = x % y;//求得余数
        x = y;//被除数更新为除数
        y = r;//除数更新为余数
    }
    return x;
}

/*******************最大公约数******************/
int maxCommonDivisor(int x, int y) {
    if (x == 0 || y == 0)return 0;
    return x * y / miniCommonMultiple(x, y);//两数之积/最小公倍数
}

/*******************分数简化******************/
void simplyFactor(int x, int y) {//分子，分母
    if (x == 0 && y != 0)return;
    if (y == 1)return;
    int tmp = miniCommonMultiple(x, y);
    printf("%d/%d", x / tmp, y / tmp);
}

/*******************守形数******************/
/*守形数是这样一种整数，它的平方的低位部分等于它本身。
比如25的平方是625，低位部分是25，因此25是一个守形数。
 */

void isShouXing(int n) {
    int m = n * n;
    char s1[10], s2[10];
    sprintf(s1, "%d", n);
    sprintf(s2, "%d", m);
    sscanf(s2 + (strlen(s2) - strlen(s1)), "%d", &m);
    if (n == m)printf("Yes\n");
    else printf("No\n");
}


/*******************丑数******************/
int result[10000];

int min(int i, int j, int k) {
    int temp = i < j ? i : j;
    return temp < k ? temp : k;
}

int getUglyNumber(int index) {
    if (index <= 0)return 0;
    result[0] = 1;
    int begin = 1, idx2 = 0, idx3 = 0, idx5 = 0;
    while (begin < index) {
        result[begin] = min(result[idx2] * 2, result[idx3] * 3, result[idx5] * 5);
        while (result[idx2] * 2 <= result[begin]) {
            idx2++;
        }
        while (result[idx3] * 3 <= result[begin]) {
            idx3++;
        }
        while (result[idx5] * 5 <= result[begin]) {
            idx5++;
        }
        begin++;
    }
    return result[index - 1];
}


/*******************中位数******************/
int midNumber(int *a, int n) {//排序之后，中位数
    int i;
//    sort(a);
    if (n % 2 == 0)return (a[n / 2] + a[n / 2 + 1]) / 2;
    else return a[n / 2];
}


/*******************进制转换******************/
void ten2Bin(int x) {//排序之后，中位数
    int a[20];
    int k = 0;
    int r = 1;
    while (x != 0) {
        r = x % 2;
        a[k++] = r;
        x /= 2;
    }
    int i;
    for (i = k - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
}

void bin2Ten(char *s) {
    char *p = s;
    int len = strlen(s) - 1;
    int sum = 0;
    while (*p != '\0') {
        int t = *p - '0';
        t *= pow(2, len--);
        sum += t;
        p++;
    }
    printf("%d\n", sum);
}


int main() {
    int x;

//    if (isPrime(x)) {
//        printf("yes");
//    } else {
//        printf("no");
//    }

//    printf("%d", miniCommonMultiple(100, 250));//50

//    simplyFactor(15, 45);//1/3

//    printf("%d", reverseNumber1(1234));
//    printf("%d", reverseNumber2(1234));

//    printf("%d",isPalin(12321));
//    printf("%d",isPalin(123221));

//    printf("%d", isNarcissistic(153));
//    printf("%d", isNarcissistic(370));

//    isFull(6);
//    isFull(10);
//    isFull(28);

//    isShouXing(625);

//    bin2Ten("100");//4
//    ten2Bin(10);//1010


    return 0;
}