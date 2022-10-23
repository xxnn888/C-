//
// Created by 15218 on 2022/10/12.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[100][100], b[100][100];//c++不让用map做变量名字......
int startx, starty, endx, endy;
int n, m;
int v = 999999;//c++不让用min做变量名字......
void dfs(int x, int y, int step) {
    int tx, ty;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    if (x == endx && y == endy) {
        if (step < v)//判断是不是最小的路径
        {
            v = step;
            return;
        }
    }
    for (int k = 0; k <= 3; k++) {
        tx = x + dx[k];
        ty = y + dy[k];
        if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if (a[tx][ty] == 0 && b[tx][ty] == 0) {
            b[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            b[tx][ty] = 0;//别忘了dfs后要变成0，要不然没法回退(回溯)了
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> startx >> starty;
    cin >> endx >> endy;
    b[startx][starty] = 1;//起始位置先标记上，表示已经走过了
    dfs(startx, starty, 0);
    cout << "从" << startx << "," << starty << "到" << endx << "," << endy << endl;
    cout << "最短路径为" << v;
    return 0;
}

