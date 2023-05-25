/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.

You have to output the maximum no of points possible.

Input
1 2 3 4

Output
20
*/


#include <iostream>
using namespace std;

int arr[1000],dp[1000][1000];
int n, ans;



void init(){
    for(int i = 0; i<1000; i++){
        arr[i] = 0;
        for(int j = 0; j<1000; j++){
            dp[i][j] = 0;
        }
    }
}

int solve(){
    for(int len = 1; len<=n; len++){
        for(int left = 1; left <= n-len+1; left++){
            int right = left+len-1;
            //cout << right << endl;
            for(int k = left; k<=right; k++){
                int temp = dp[left][k-1]+dp[k+1][right];
                if(left == 1 && right == n){
                    temp+=arr[k];
                }
                else{
                    temp+= arr[left-1]*arr[right+1];
                }
                dp[left][right] = max(dp[left][right], temp);
            }
        }
    }

    return dp[1][n];
}

int main(){
    cin >> n;
    init();
    arr[0] = 1;
    arr[n+1] = 1;
    for(int i = 1; i<= n; i++){
        cin >> arr[i];
    }
    cout << solve() << endl;
}
