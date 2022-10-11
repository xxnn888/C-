#include<cstdio>

using namespace std;
int m, n, endx, endy, min = 999;
int a[100][100];//1表示空地 2 表示障碍物
int v[100][100];//0表示未访问 0表示访问
int dx[4] = {0, 1, 0, -1};//四个方向，右，下，左，上
int dy[4] = {1, 0, -1, 0};

void DFS(int x, int y, int step) {
    if (x == endx && y == endy) {
        if (step < min)
            min = step;
        return;
    }
    //顺时针试探   按照 右 下 左 上 顺序去寻找
    for (int k = 0; k <= 3; k++) {
        int tx, ty;
        tx = x + dx[k];
        ty = y + dy[k];
        if (a[tx][ty] == 1 && v[tx][ty] == 0) {
            v[tx][ty] = 1;
            DFS(tx, ty, step + 1);
            v[tx][ty] = 0;
        }
    }
}

int main() {
    int startx, starty;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);//1表示空地 2 表示障碍物
        }
    }
    scanf("%d%d%d%d", &startx, &starty, &endx, &endy);
    v[startx][starty] = 1;
    DFS(startx, starty, 0);
    printf("%d", min);
    return 0;
}