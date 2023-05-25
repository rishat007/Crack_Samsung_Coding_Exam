#include <iostream>
#define lim 10

using namespace std;

int visited[lim], wh[lim][5];
int ans,N;

int abs(int x){
    if(x>=0)
        return x;
    else
        return -x;
}

int distance(int sx, int sy, int dx, int dy){
    return (abs(sx-dx)+abs(sy-dy));
}

void fn(int sx, int sy, int dx, int dy, int dis){
    ans = min(ans, distance(sx, sy, dx, dy)+dis);

    for(int i=0; i<N; i++){
        if(visited[i]==0){
            visited[i]=1;
            int temp = distance(sx, sy, wh[i][0], wh[i][1])+wh[i][4]+dis;
            fn(wh[i][2], wh[i][3], dx, dy, temp);
            temp = distance(sx, sy, wh[i][2], wh[i][3])+wh[i][4]+dis;
            fn(wh[i][0], wh[i][1], dx, dy, temp);
            visited[i]=0;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        cin>>N;
        int sx, sy, dx, dy;
        cin>>sx>>sy>>dx>>dy;
        for(int i=0; i<N; i++){
            visited[i]=0;
            for(int j=0; j<5; j++){
                cin>>wh[i][j];
            }
        }
        ans=999999;
        fn(sx, sy, dx, dy, 0);
        cout<<ans<<endl;
    }
}