/*
It is a well-researched fact that men in a restroom generally prefer to maximize their distance from already occupied stalls, by occupying the middle of the longest sequence of unoccupied places. For example, consider the situation where ten stalls are empty.

The first visitor will occupy a middle position:

_ _ _ _ _ X _ _ _ _

The next visitor will be in the middle of the empty area at the left.

_ _ X _ _ X _ _ _ _

Write a program in Java that reads the number of stalls and then prints out diagrams in the format given above when the stalls become filled, one at a time. Hint: Use an array of boolean values to indicate whether a stall is occupied.
Example of the output for the number of stalls = 10

_ _ _ _ X _ _ _ _ _

_ _ _ _ X _ _ X _ _

_ X _ _ X _ _ X _ _

_ X _ _ X _ _ X X _

_ X _ _ X X _ X X _

_ X X _ X X _ X X _

_ X X _ X X _ X X X

_ X X _ X X X X X X

_ X X X X X X X X X

X X X X X X X X X X

*/


#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    string stalls(n, '_');

    queue<pair<int,int>> q;
    q.push({0, n-1});

    while(!q.empty()){
        int left = q.front().first;
        int right  =q.front().second;
        q.pop();

        int mid = (left+right)/2; //left+(right-left)/2;
        stalls[mid] = 'X';

        if(left <= mid-1){
            q.push({left, mid-1});
        }
        if(right >= mid+1){
            q.push({mid+1, right});
        }

        cout << stalls <<endl;
    }
}