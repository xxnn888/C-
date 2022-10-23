//
// Created by 15218 on 2022/10/12.
//

#include <cstdio>
#include <cstdlib>

#define M 4
#define N 4

typedef struct {
    int i, j;    //记录方块的行数与列数
    int pre;    //记录本路径上一方块在队列中的下标
} Box;

typedef struct {
    Box data[1000];
    int front, rear;    //队头队尾指针
} Que;

int mg[M + 2][N + 2] =
        {{1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 1, 1},
         {1, 0, 1, 0, 0, 1},
         {1, 0, 0, 0, 1, 1},
         {1, 1, 0, 0, 0, 1},
         {1, 1, 1, 1, 1, 1}
        };

void InitQue(Que *&qu) {
    qu = (Que *) malloc(sizeof(Que));
    qu->front = qu->rear = -1;
}

bool EmptyQue(Que *&qu) {
    return (qu->front == qu->rear);
}

bool Push(Que *&qu, Box &e) {
    if (qu->rear > 999)
        return false;
    e.pre = qu->front;
    qu->rear++;
    qu->data[qu->rear] = e;
    return true;
}

bool Pop(Que *&qu, Box &e) {
    if (EmptyQue(qu))
        return false;
    qu->front++;
    e = qu->data[qu->front];
    return true;
}

void print(Que *&qu, int k) {
    int j;
    //反向寻找最短路径
    while (k != -1) {
        j = k;
        k = qu->data[k].pre;
        qu->data[j].pre = -1;    //将找到的路径上的方块的pre成员置为-1
    }

    k = 0;
    int ns = 0;
    while (k < 1000) {    //遍历整个队列输出pre成员为-1的方块坐标
        if (qu->data[k].pre == -1) {
            ns++;
            printf("\t(%d,%d)", qu->data[k].i, qu->data[k].j);
            if (ns % 5 == 0) printf("\n");    //每输出5个元素后换一行
        }
        k++;
    }
    printf("\n");
}

void DestroyQue(Que *&qu) {
    free(qu);
}

bool mgpath1(int xi, int yi, int xe, int ye) {
    Box e;
    int i, j, pre;
    Que *qu;
    InitQue(qu);    //初始化队列

    //起点入队
    e.i = xi, e.j = yi, e.pre = -1;
    mg[xi][yi] = -1;
    Push(qu, e);

    while (!EmptyQue(qu)) {    //队列不空则循环
        Pop(qu, e);    //队首元素出队
        i = e.i, j = e.j, pre = e.pre;    //记录当前队首元素的方块类
        if (i == xe && j == ye) {    //队首元素为出口则输出路径
            print(qu, qu->front);    //输出路径函数
            return true;
        }

        int d = -1;
        int in, jn;
        while (d < 4) {    //每个方位进行试探
            d++;
            switch (d) {
                case 0: {
                    in = i - 1, jn = j;
                    break;
                }
                case 1: {
                    in = i;
                    jn = j + 1;
                    break;
                }
                case 2: {
                    in = i + 1;
                    jn = j;
                    break;
                }
                case 3: {
                    in = i;
                    jn = j - 1;
                    break;
                }
            }
            if (mg[in][jn] == 0) {    //找到可走相邻方块(in,jn)就入队
                e.i = in, e.j = jn, e.pre = qu->front;
                Push(qu, e);
                mg[in][jn] = -1;    //将其赋值-1，以避免来回重复搜索
            }
        }
    }
    DestroyQue(qu);    //销毁队列
    return false;
}

int main() {
    if (!mgpath1(1, 1, M, N))
        printf("此迷宫问题无解");

    return 0;
}
