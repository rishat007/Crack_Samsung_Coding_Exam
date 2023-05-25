/*
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. You want to pick up the jewels after getting into the maze through the entrance and before getting out of it through the exit. You want to get as many jewels as possible, but you don’t want to take the same passage you used once.
When locations of a maze and jewels are given, find out the greatest number of jewels you can get without taking the same passage twice, and the path taken in this case.
Input
There can be more than one test case in the input file. The first line has T, the number of test cases. Then the totally T test cases are provided in the following lines (T ≤ 10 ).
In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. The maze is N×N square-shaped. From the second line through N lines, information of the maze is given. “0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located on the upper-most left passage and the exit is located on the lower-most right passage. There is no case where the path from the entrance to the exit doesn’t exist.
Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the greatest number of jewels that can be picked up. Each test case must be output separately as a empty.
MAX DIAMONDS COLLECTED AND ITS PATH IS THE OUTPUT.
*/

#include <iostream>
using namespace std;
int arr[100][100];
int ans[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, jewels;
void init(){
    for(int i = 0 ; i<100; i++){
        for(int j = 0; i<100; j++){
            arr[i][j] = 0;
            ans[i][j] = 0;
        }
    }
}
bool isValid(int x, int y){
    return ((arr[x][y] == 0 || arr[x][y] == 2) && x>=0 && x<n && y>=0 && y<n);
}

void dfs(int sx, int sy, int jwl){
    if(sx == n-1 && sy == n-1){
        if(jwl > jewels){
            jewels = jwl;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    ans[i][j] = arr[i][j];
                }
            }
        }
        return;
    }
    for(int i = 0; i<4; i++){
        int new_x = sx+dx[i];
        int new_y = sy+dy[i];
        if(isValid(new_x, new_y)){
            int collect = 0;
            if(arr[new_x][new_y] == 2){
                collect =1;
            }
            arr[new_x][new_y] = 3;
            dfs(new_x, new_y, collect+jwl);
            if(collect == 1){
                arr[new_x][new_y] = 2;
            }
            else{
                arr[new_x][new_y] = 0;
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t<=tc; t++){
        cin >> n;
        //init();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                cin >> arr[i][j];
            }
        }

        jewels = -1;
        arr[0][0] = 3;
        dfs(0,0,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<ans[i][j]<<" ";
            }
            cout << endl;
        }
        cout << jewels<<endl;
    }

}