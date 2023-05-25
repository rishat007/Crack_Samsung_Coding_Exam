/*
Given an integer k and a monotonic increasing sequence:
f(n) = an + bn [log2(n)] + cn^3 where (a = 1, 2, 3, …), (b = 1, 2, 3, …), (c = 0, 1, 2, 3, …)
Here, [log2(n)] means, taking the log to the base 2 and round the value down Thus,
if n = 1, the value is 0.
if n = 2-3, the value is 1.
if n = 4-7, the value is 2.
if n = 8-15, the value is 3.
The task is to find the value n such that f(n) = k, if k doesn’t belong to the sequence then print 0.

Note: Values are in such a way that they can be expressed in 64 bits and the three integers a, b and c do not exceed 100.

Examples:

Input: a = 2, b = 1, c = 1, k = 12168587437017
Output: 23001
f(23001) = 12168587437017

Input: a = 7, b = 3, c = 0, k = 119753085330
Output: 1234567890
*/

#include <iostream>
#include <math.h>

//#define long long long long
#define SMALL_N 1000000
#define LARGE_N  1000000000000000

using namespace std;


long long func(long long a, long long b, long long c, long long n){
    long long res = a*n;
    long long logFunc = floor(log2(n));
    res+= (b*n*logFunc);
    res+= (c*(n*n*n));

    return res;
}

long long getPosition(long long a, long long b,long long c, long long k){
    long long start  = 1, end = SMALL_N;

    if(c == 0){
        end = LARGE_N;
    }
    long long ans = 0;

    while(start <= end){

        long long mid = (start+end) / 2;
        long long val = func(a,b,c,mid);
        //cout << val << endl;
        if(val == k){
            ans = mid;
            break;
        }
        else if(val > k){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return ans;
}

int main(){
    long long a,b,c,k;
    cin >> a >> b >> c >> k;

    cout << getPosition(a,b,c,k)<<endl;
}