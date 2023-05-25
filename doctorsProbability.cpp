/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and
the edge weights are the probabilities of the doctor going from that division to other connected division but the
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be
staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division
in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling
time is not considered and during that 10min at 10th min he will be in next division, so be careful
2
6 10 40
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 0.774000
3 0.700000
*/


#include <iostream>
#include<iomanip>
using namespace std;
float arr[100][100], prob =1;
float ans[100];
float n, e, t;
void init(){
    for(int i = 0; i<100; i++){
        ans[i] = 0.0;
        for(int j = 0; j<100; j++){
            arr[i][j] = 0.0;
        }
    }
}
void dfs(int src, int time){
    if(time <=0){ //it was <= 0
        ans[src] += prob;
        return;
    }
    for(int i = 1; i<=n;i++){
        if(arr[src][i] != 0.0){
            prob*=arr[src][i];
            dfs(i, time-10);
            prob/=arr[src][i];
        }

    }
}
int main(){
    int testcase;
    cin >> testcase;
    for(int tc  = 1; tc<=testcase; tc++){
        cin >> n >> e >> t;
        init();
        for(int i = 1; i<=e; i++){
            int src, dst;
            float p;
            cin >> src >> dst >> p;
            arr[src][dst] = p;
        }

        dfs(1, t);
        int final_dest = 0;
        float final_prob = -1;
        for(int i = 1; i<=n; i++){
            if(ans[i] > final_prob){
                final_prob = ans[i];
                final_dest = i;
            }
        }

        cout <<"#"<<tc<<" "<<final_dest<<" "<<setprecision(6)<<fixed<<final_prob<<endl;
    }
}