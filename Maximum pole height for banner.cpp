/*
You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2..
Then pillars can be,
p1 = 3 unitâ¦ Choosing element (3) from array,
Similarly p2 = 3 choosing (2 + 1) from array.
Since, two pillars are equal, we can put board on itâ¦
But we have two maximise the height of the pillars,
And if we check for other heights, we can see p1 = 6 p2 = 4 + 2 which is greater than 3 ( the previous height)..
We have to see if we can further maximize the heightâ¦ Yes it can be 8.
I.e. p1 = 6 + 2 = 8. p2 = 4 + 3 + 1 = 8.
Both pillars are equal and banner can be placedâ¦ And since this is the maximum height attainable for two pillars, we print the answer as 8. In case, there is no combination possible, print 0 (zero).

INPUT :
1
5
1 2 3 4 6
First line is  T  number of test cases to be followed.
Second line of input is number of different pillars.
Third line of input is  different available heights of pillars.
Note : heights of given pillars can be same .. I.e. array can have same elements repeated.

Output.
8
*/

#include <iostream>

using namespace std;

int pillers[100], ans, p;
int taken[100];

void init(){
    for(int i = 0; i<100; i++){
        pillers[i] = 0;
        taken[i] = 0;
    }
}

void maxHeight(int pillers[], int p1, int p2){
    if(p1 == p2){
        ans = max(ans, p1);
    }

    for(int i = 0; i<p; i++){
        if(!taken[i]){
            taken[i] = 1;
            maxHeight(pillers, p1+pillers[i], p2);
            maxHeight(pillers, p1, p2+pillers[i]);
            taken[i] = 0;
        }
    }
}


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> p;
        for(int i = 0; i<p; i++){
            cin >> pillers[i];
        }

        ans = INT_MIN;
        maxHeight(pillers, 0, 0);
        cout << ans <<endl;
    }
}