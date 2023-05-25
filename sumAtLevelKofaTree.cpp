/*
3
(0(5(6()())(4()(9()())))(7(1()())(3()())))
1
(0(5(6()())(4()(9()())))(7(1()())(3()())))
2
(0(5(6()())(4()(9()())))(7(1()())(3()())))
3

Answers
12 14 9
*/

#include <iostream>

using namespace std;

int main(){
    int k;
    string str;
    cin >> k >> str;
    int ans = 0;
    int lvl = -1;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == '('){
            lvl++;
        }
        else if(str[i] == ')'){
            lvl--;
        }
        else if(lvl == k){
            ans+=(str[i]-'0');
        }
        i++;
    }

    cout << ans << endl;
}