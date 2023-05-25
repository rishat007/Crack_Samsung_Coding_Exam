//DFS Solution on adjacency matrix

#include <iostream>

using namespace std;

int n;
int arr[100][100];

bool isBipartite(int i, int col, int color[]){
    color[i] = col;

    for(int j = 0; j<n; j++){
        if(arr[i][j] == 1){
            if(color[j] == -1){
                if(!isBipartite(j, !col, color)){
                    return false;
                }
            }
            else{
                if(color[i] == color[j]){
                    return false;
                }
            }
        }
    }

    return true;
}

int main(){

    cin >> n;
    int color[100];
    for(int i = 0; i<100; i++){
        color[i] = -1;
        for(int j = 0; j<100; j++){
            arr[i][j] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        if(color[i] == -1){
            if(!isBipartite(i, 0, color)){
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(color[i] == 0){
            cout <<i<<" ";
        }
    }
}