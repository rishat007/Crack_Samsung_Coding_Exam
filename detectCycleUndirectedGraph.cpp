//https://cses.fi/problemset/task/1669/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

bool dfs(int src, int par, vector<int> graph[], vector<int>& res, vector<bool>& visited){
    visited[src] = true;
    res.push_back(src);
    for(auto v:graph[src]){
        if(!visited[v]){
            if(dfs(v, src, graph, res, visited)) return true;
        }
        else if(par != v){
            res.push_back(v);
            return true;
        }
    }
    res.pop_back();
    return false;
}
int main(){
    int m, n;
    cin>> n >> m;
    vector<int> graph[n];
    vector<int> res;
    vector<bool> visited(n, false);
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //bool flag  = false;
    if(dfs(1, -1, graph, res, visited)){
        vector<int> temp;
        int ch = res[res.size()-1];
        temp.push_back(ch);
        for(int i = res.size()-2; i>=0; i--){
            if(res[i] == ch){
                temp.push_back(res[i]);
                break;
            }
            else{
                temp.push_back(res[i]);
            }
        }
        cout<< temp.size()<<endl;
        for(auto it:temp){
            cout << it<<" ";
        }

    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}