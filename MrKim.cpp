#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int x[100], y[100], n, ans;
int distance(int i, int j){
    int x1 = x[i];
    int y1 = y[i];
    int x2 = x[j];
    int y2 = y[j];

    return (abs(x1-x2)+abs(y1-y2));
}

void minPath(int currSrc, bool visited[], int node, int dist){
    if(node == n){
        ans = min(ans, dist+distance(currSrc, n+1));
        return;
    }
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            minPath(i, visited, node+1, dist+distance(currSrc, i));
            visited[i] = false;
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    for(int t = 1; t<=tc; t++){
        ans = 1e9;
        cin >> n;
        cin >> x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i = 1; i<=n; i++){
            cin >> x[i] >> y[i];
        }
        bool visited[n+2] = {false};
        minPath(0, visited, 0, 0);
        cout<<"#"<<t<<" "<<ans<<endl;
    }
    return 0;
}
