#include <iostream>

using namespace std;
struct node{
    int x, y, length;
};
int arr[1000][1000], visited[1000][1000];
node queue[10000000];
int row, col, X, Y, L;
int front, back;
void init(){
    front = 0;
    back = 0;
}
void push(node temp){
    queue[back++] = temp;
}
node pop(){
    return queue[front++];
}

bool empty(){
    return front == back;
}
bool valid(int x , int y){
    if(x >= 0 && x < row && y>=0 && y < col){
        return true;
    }

    return false;
}

bool up(int x, int y){
    return (arr[x][y] == 1 || arr[x][y] == 2 || arr[x][y] == 4 || arr[x][y] == 7);
}
bool down(int x, int y){
    return (arr[x][y] == 1 || arr[x][y] == 2 || arr[x][y] == 5 || arr[x][y] == 6);
}
bool left(int x, int y){
    return (arr[x][y] == 1 || arr[x][y] == 3 || arr[x][y] == 6 || arr[x][y] == 7);
}
bool right(int x, int y){
    return (arr[x][y] == 1 || arr[x][y] == 3 || arr[x][y] == 4 || arr[x][y] == 5);
}
int solve(int x, int y, int l){
    push({x,y,l});
    visited[x][y] =1;
    int ans = 0;
    while(!empty()){
        node temp = pop();
        int x = temp.x;
        int y = temp.y;
        int l = temp.length;
        if(l ==  0) continue;


        ans++;
        //going up;
        if(valid(x-1,y) && up(x, y) && down(x-1, y) && visited[x-1][y] == 0){
            push({x-1, y, l-1});
            visited[x-1][y] =1;
        }
        //going down
        if(valid(x+1, y) && down(x,y) && up(x+1, y) && visited[x+1][y] == 0){
            push({x+1,y, l-1});
            visited[x+1][y] = 1;
        }
        //going left
        if(valid(x, y-1) && left(x,y) && right(x, y-1) && visited[x][y-1] == 0){
            push({x, y-1, l-1});
            visited[x][y-1] = 1;
        }
        //going right
        if(valid(x, y+1) && right(x, y) && left(x, y+1) && visited[x][y+1] == 0){
            push({x, y+1, l-1});
            visited[x][y+1] =1;
        }
    }
    return ans;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        init();
        cin>>row>>col>>X>>Y>>L;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                cin >> arr[i][j];
                visited[i][j] = 0;
            }
        }
        if(arr[X][Y] > 0){
            //ans = 0;
            cout <<solve(X,Y,L)<<endl;
        }
        else{
            cout <<0<<endl;
        }

        //cout << ans << endl;
    }

}