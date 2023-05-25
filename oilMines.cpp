 /*
https://www.careercup.com/question?id=5740719907012608
https://stackoverflow.com/questions/39673898/divide-array-into-k-contiguos-partitions-such-that-sum-of-maximum-partition-is-m/39675396
http://ideone.com/r60yH4 - Sameer Code
https://www.careercup.com/question?id=5730470801702912
*/

/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil
mines adjacent to each other and not in between of each others.After distributing them compute the
difference of oil mines from the company getting highest and company getting lowest. This number
should be minimum.(then only the distribution can be termed as fair).
Input
2
2 4
6 13 10 2
2 4
6 10 13 2
output
5
1
*/

#include <iostream>

using namespace std;

int oil[100], vis[100];
void init(){
    for(int i = 0; i<100; i++){
        oil[i] = vis[i] = 0;
    }
}
int c, m, ans; //company, mines, answer

void solve(int i, int minVal, int maxVal, int sum, int nodes){
    if(vis[i]){
        int new_min = min(sum, minVal);
        int new_max = max(sum, maxVal);
        if(nodes == c-1){
            ans = min(ans, new_max-new_min);
        }
        return;
    }

    vis[i] = 1;
    int j = (i+1) % m;
    solve(j, minVal, maxVal, sum+oil[i], nodes);
    int new_min = min(sum, minVal);
    int new_max = max(sum,maxVal);
    solve(j, new_min, new_max, oil[i], nodes+1);
    vis[i] = 0;

}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        init();
        cin >> c >> m;
        for(int i = 0; i<m; i++){
            cin >> oil[i];
        }
        ans = INT_MAX;
        for(int i = 0; i<m; i++){
            solve(i, INT_MAX, INT_MIN, 0,0);
        }

        cout << ans << endl;
    }
}