#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int n,m,o;
    cin>>n>>m>>o;
    int arr[n];
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        q.push(make_pair(arr[i],1));
    }
    int op[m];
    for(int i=0;i<m;i++) cin>>op[i];
    unordered_map<int,int> mp;
    for(int i=0;i<m;i++) mp[op[i]]=1;
    int target;
    cin>>target;
    int ans=INT_MAX;
    while(!q.empty())
    {
        int num=q.front().first;
        int count=q.front().second;
        if(num==target) ans=min(ans,count);
        q.pop();
        for(int i=0;i<=4;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and count+1<=o)
                {
                    q.push(make_pair(num*10+arr[j],count+1));
                }
                else
                {
                    if(i==1 and mp.find(i)!=mp.end() and count+3<=o)
                    {
                        q.push(make_pair(num+arr[j],count+3));
                    }
                    if(i==2 and mp.find(i)!=mp.end() and count+3<=o)
                    {
                        q.push(make_pair(abs(num-arr[j]),count+3));
                    }
                    if(i==3 and mp.find(i)!=mp.end() and count+3<=o)
                    {
                        q.push(make_pair(num*arr[j],count+3));
                    }
                    if(i==4 and mp.find(i)!=mp.end() and count+3<=o)
                    {
                        q.push(make_pair(num/arr[j],count+3));
                    }
                }
            }
        }
    }
    if(ans==INT_MAX) cout<<"-1"<<endl;
    else cout<<ans<<endl;

    return 0;
}