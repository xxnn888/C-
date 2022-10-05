//
// Created by 15218 on 2022/10/5.
//

#include <iostream>

using namespace std;
#define MAXSIZE 50    //定义队列中元素的最大个数
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];    //存放队列元素
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *&Q)  //初始化队列，构造一个空队列Q
{
    Q = (SqQueue *) malloc(sizeof(SqQueue));
    Q->front = Q->rear == -1;
}

bool QueueEmpty(SqQueue Q)//判队列空，若队列Q为空返回true，否则返回false。
{
    return (Q.rear == Q.front);
}

bool EnQueue(SqQueue *&Q, int X)//入队，若队列Q未满，将x加入，使之成为新的队尾。
{
    if (Q->rear == MAXSIZE) return false;
    Q->data[Q->rear++] = X;
    return true;
}

bool DeQueue(SqQueue *&Q, int &x)//若队列Q非空，删除队头元素，并用x返回。
{
    if (Q->rear == Q->front) return false;
    Q->front++;
    x = Q->data[Q->front];
    return true;
}

void GetHead(SqQueue &Q, int &x)//读队头元素，若队列Q非空，则将队头元素赋值给x。
{
    if (Q.front == Q.rear) return;
    x = Q.data[Q.front++];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
