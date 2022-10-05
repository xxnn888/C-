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
    Q->front = Q->rear == 0;
}

bool QueueEmpty(SqQueue Q)//判队列空，若队列Q为空返回true，否则返回false。
{
    return (Q.rear == Q.front);
}

bool EnQueue(SqQueue *&Q, int X)//入队，若队列Q未满，将x加入，使之成为新的队尾。
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) return false;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->data[Q->rear] = X;
    return true;
}

bool DeQueue(SqQueue *&Q, int &x)//若队列Q非空，删除队头元素，并用x返回。
{
    if (Q->rear == Q->front) return false;
    Q->front = (Q->front + 1) % MAXSIZE;
    x = Q->data[Q->front];
    return true;
}

//求队列中的元素个数
int Count(SqQueue *q) {
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
