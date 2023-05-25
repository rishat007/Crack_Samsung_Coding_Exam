#include<iostream>

using namespace std;
int arr[100][100];
int n;
void init(){
    for(int i = 0; i<100; i++){
        for(int j = 0; j<100; j++){
            arr[i][j] = 0;
        }
    }
}
bool isValid(int r, int c){
    if(r<n && r>=0 && c<5 && c>=0)
        return true;


  return false;
}

//Use of effect variable is that we can use bomb once and kill enemy in 5 level
int solve(int row, int col, int bomb, int effect){
    if(row < 0){
        return 0;
    }
    int ans = 0, temp = 0;
    for(int i = -1; i<=1; i++){
        int x = row-1;
        int y = col+i;

        if(isValid(x, y)){
            if(arr[x][y] == 2){ //meet with enemy
                if(bomb == 0 && effect > 0){
                    temp = solve(x, y, bomb, effect-1);
                }
                if(bomb == 1){
                    temp = solve(x, y, bomb-1, 5);
                }
            }
            //found coins
            if(arr[x][y] == 1 || arr[x][y] == 0){
                if(bomb == 0){
                    temp = solve(x, y, bomb, effect-1);
                }
                else{
                    temp = solve(x, y, bomb, 5);
                }
            }
        }
        ans = max(ans, temp);
    }

    if(arr[row][col] ==1){
        ans++;
    }
    return ans;
}

int main(){

    int tc;
    cin >> tc;
        for(int t = 1; t<= tc; t++){
            cin >> n;
        init();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<5; j++){
                cin >> arr[i][j];
            }
        }

        if(solve(n, 2, 1, 0) == 0){
            cout <<"#"<<t<<" -1"<<endl;
        }
        else{
            cout <<"#"<<t<<" "<< solve(n, 2, 1, 0)<<endl;
        }
    }
}