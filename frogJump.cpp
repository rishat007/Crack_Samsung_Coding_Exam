/*Given a 2 D matrix where 1 represents the places where the frog can jump and 0 represent the empty spaces, the frog can move freely in the horizontal direction (on 1’s only) without incurring any cost (jump). A vertical jump from a given point of the matrix to another point on the matrix can be taken (on 1’s only) with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump)*/

#include <iostream>

using namespace std;

int arr[100][100];
int ans[100][100];

int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};
struct point{
    int x, y;
};
int n, m;
void solve(int x, int y, int count){
    if(ans[x][y] > count){
        ans[x][y] = count;
        for(int i = 0; i<3; i++){
            int new_x = x+xx[i];
            int new_y = y+yy[i];

            if(new_x >= 1 && new_x <=n && new_y >= 1 && new_y <= m && arr[new_x][new_y] == 1){
                int temp;
                if(new_x == x) temp = 0;
                if(new_y == y) temp = 1;
                solve(new_x, new_y, temp+count);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> arr[i][j];
            ans[i][j] = INT_MAX;
        }
    }
    point src, ds;
    cin >> src.x >> src.y >> ds.x >> ds.y;
    solve(src.x, src.y, 0);

    cout << ans[ds.x][ds.y]<<endl;
}
