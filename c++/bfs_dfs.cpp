//
// Created by jasonhaven on 18-12-16.
//

#include <iostream>
#include <queue>


using namespace std;
//#define N 5
//int maze[N][N] = {
//        {0, 1, 1, 0, 0},
//        {0, 0, 1, 1, 0},
//        {0, 1, 1, 1, 0},
//        {1, 0, 0, 0, 0},
//        {0, 0, 1, 1, 0}
//};

/*
 * BFS: 1 2 3 4 5
 * DFS: 1 2 3 4 5
 * */


//指导书p193页
#define N 8
int maze[N][N] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0}
};
/*
 * BFS: 1 2 3 4 5 6 7 8
 *
 * DFS: 1 2 4 5 8 3 6 7
 *
 * */

int visited[N + 1] = {0,};

void BFS(int start) {//[1,N]
    queue<int> Q;
    Q.push(start);//注意：将下标start入队就是将当前顶点入队
    visited[start] = 1;//入队的时候设置访问标志=1
    while (!Q.empty()) {
        int front = Q.front();
        cout << front << " ";
        Q.pop();
        for (int i = 1; i <= N; i++)//遍历全部顶点，为了找到当前顶点的邻接点
        {
            //注意：遍历迭代器i的范围是[1,N],二维数组存储范围是[0,N-1]
            if (!visited[i] && maze[front - 1][i - 1] == 1)//第front顶点所在行即表示front顶点的邻接点，如果没有被访问过，将相邻的顶点加入队列，
            {
                Q.push(i);
                visited[i] = 1;//入队的时候设置访问标志=1
            }
        }
    }
}


void DFS(int start) {//[1,N]
    visited[start] = 1;//入队的时候设置访问标志=1
    cout << start << " ";
    for (int i = 1; i <= N; i++)//遍历全部顶点，为了找到当前顶点的邻接点
    {
        if (!visited[i] && maze[start - 1][i - 1] == 1)//第front顶点所在行即表示front顶点的邻接点，如果没有被访问过
        {
            DFS(i);
            visited[i] = 1;//入队的时候设置访问标志=1
        }
    }
}


void Start_BFS() {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 1)
            continue;
        BFS(i);//将1....N个顶点依次作为遍历起点，进行广度遍历,下标1,2,3,4...就表示顶点
    }
}

void Start_DFS() {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 1)
            continue;
        DFS(i);//将1....N个顶点依次作为遍历起点，进行广度遍历,下标1,2,3,4...就表示顶点
    }
}

//int main() {
//    Start_BFS();
//    Start_DFS();
//    return 0;
//}