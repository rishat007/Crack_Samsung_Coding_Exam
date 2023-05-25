#include <bits/stdc++.h>

using namespace std;

vector<int> visited(100,0);
vector<int> adj[100];
vector <int> cycle;

bool cycleCheck(int node){

    cycle.push_back(node);

    for(auto v: adj[node]){
        if(!visited[v]){
            visited[v] = 1;
            if(cycleCheck(v)){
                return true;
            }

        }
        else if(visited[v]){
            cycle.push_back(v);
            return true;
        }
    }
    cycle.clear();
    return false;
}
int main(){

    int nodes, edges;
    cin >> nodes >> edges;

    for(int i = 0; i<edges; i++){
        int from, to;
        cin >> from >> to;

        adj[from].push_back(to);
    }

    for(int i = 0; i<nodes; i++){
        if(!visited[i]){
            visited[i] = 1;
            if(cycleCheck(i)){
                for(auto it:cycle){
                    cout << it <<" ";
                }
                cout << endl;
                break;
            }
            else{
                cout <<0<<endl;
            }
        }
    }
}