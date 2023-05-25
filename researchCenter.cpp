/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.
Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road.
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/
/*
For this you have to implement bfs for every position where road exist to find the distance of
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them
Input -
*/
/*
https://www.careercup.com/question?id=5707238197952512
https://practice.geeksforgeeks.org/problems/how-to-solve-this-bfs-problem-asked-in-samsung
https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092
1 Bsed -> https://sapphireengine.com/@/4q0evk - Ajay Verma
0 Bsed -> https://sapphireengine.com/@/iha4kq - Thusoo
*/

/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.
Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.
Locations are given in the matrix cell form where 1 represents roads and 0 no road.
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them
Input -
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1
Output -
1
2
2
12
15
4
*/

#include<bits/stdc++.h>
using namespace std;
int t, n, c;
int rare[5][2];
int arr[100][100];
int visited[100][100];
struct node{
	int x, y, level;
};
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};
bool valid(node tmp){
	if(tmp.x >= 0 and tmp.y >= 0 and tmp.x < n and tmp.y < n)return true;
	return false;
}
int bfs(int sx, int sy, int dx, int dy){
	
	queue<node>q;
	node tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.level = 0;
	q.push(tmp);
	visited[tmp.x][tmp.y] = 1;

	while(!q.empty()){
		tmp = q.front();
		if(tmp.x == dx and tmp.y == dy)break;
		q.pop();
		for(int i = 0; i < 4; i++){
			node new_tmp;
			new_tmp.x = x[i] + tmp.x;
			new_tmp.y = y[i] + tmp.y;
			new_tmp.level = tmp.level + 1;
			if(valid(new_tmp) and arr[new_tmp.x][new_tmp.y] == 1 and visited[new_tmp.x][new_tmp.y] == 0){
				q.push(new_tmp);
				visited[new_tmp.x][new_tmp.y] = 1;
			}
		}
	}
	return tmp.level;
}
int main(){
	cin>>t;
	for(int test_case = 1; test_case <= t; test_case++){
		cin>>n>>c;
		for(int i = 0; i < c; i++){
			int x, y;
			cin>>x>>y;
			rare[i][0] = x-1;
			rare[i][1] = y-1;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin>>arr[i][j];
			}
		}
		int ans = 1000000;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int tmp;
				if(arr[i][j] == 1){
					//check all possibilities
					tmp = 0;
					for(int k = 0; k < c; k++){
						memset(visited, 0, sizeof(visited));
						int res = bfs(i, j, rare[k][0], rare[k][1]);
						tmp = max(tmp, res);
					}
				}
				ans = min(ans, tmp);
			}
		}
		cout<<'#'<<test_case<<" "<<ans<<endl;
	}
}