/*
Given:
Fishing Spots: 1 to N
3 Gates with gate position and number of fishermen waiting to get in
Distance between consecutive spots = distance between gate and nearest spot = 1 m

Fishermen are waiting at the gates to get in and occupy nearest fishing spot. Only 1 gate can be opened at visited time and all fishermen of that gate must occupy spots before next gate is open.
There could be 2 spots closest to the gate. Assign only 1 spot to the last fisherman in such visited way that we get minimum walking distance. For rest of the fishermen, ignore and assign any one.

Write visited program to return sum of minimum distance need to walk for fishermen.

Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot.
If the gate is at position 4, then fishermen occupying spot 4 will walk 1 m,
Test Cases:
5
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16

outputs
18
25
57
86
339
*/


#include <bits/stdc++.h>
using namespace std;

int gate[4], fishermen[4], visited[1000];
int n, ans = INT_MAX;
void init(){
    for(int i =0; i<1000; i++){
        visited[i] = 0;
    }
}

int findRight(int idx){
    for(int i = idx; i<=n; i++){
        if(visited[i] == 0){
            return i;
        }
    }
    return INT_MAX;
}

int findLeft(int idx){
    for(int i = idx-1; i>0; i--){
        if(visited[i] == 0){
            return i;
        }
    }
    return INT_MAX;
}



void solve(int x, int y, int z, int currPos, int cost){
    if(cost > ans) return;

    if(fishermen[currPos] == 0){
        if(currPos == x){
            currPos = y;
        }
        else if(currPos == y){
            currPos = z;
        }
        else{
            ans = min(ans,cost);
            return;
        }
    }

    int leftPos = findLeft(gate[currPos]);
    int rightPos = findRight(gate[currPos]);

    int leftCost = abs(gate[currPos]-leftPos+1);
    int rightCost = abs(rightPos-gate[currPos]+1);

    int goTo = leftCost>rightCost? rightPos:leftPos;
    
    int goToCost = min(leftCost, rightCost);

    //if there is 1 fishermen leftPos
    if(fishermen[currPos] == 1 && leftCost == rightCost){

        //Go Left
        visited[leftPos] = 1;
        fishermen[currPos] --;
        solve(x,y,z, currPos, cost+leftCost);
        visited[leftPos] = 0;
        fishermen[currPos]++;

        //go rightPos
        visited[rightPos] = 1;
        fishermen[currPos]--;
        solve(x,y,z,currPos,cost+rightCost);
        visited[rightPos] = 0;
        fishermen[currPos]++;
    }
    else{
        visited[goTo] = 1;
        fishermen[currPos]--;
        solve(x,y,z,currPos, cost+goToCost);
        visited[goTo] = 0;
        fishermen[currPos]++;
    }
}


int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t<=tc; t++){
        cin >> n;
        for(int i = 1; i<= 3; i++){
            cin >> gate[i] >> fishermen[i];
        }
        init();
        ans = INT_MAX;
        solve(1,2,3,1,0);
        init();
        solve(1,3,2,1,0);
        init();
        solve(2,3,1,2,0);
        init();
        solve(2,1,3,2,0);
        init();
        solve(3,1,2,3,0);
        init();
        solve(3,2,1,3,0);
        init();

        cout <<"#"<<t<<" "<<ans<<endl;
    }
}