#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
using namespace std;

inr n,m;
inr a[N];
priority_queue<inr,vector<inr>,greater<inr>>pq;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bai4.inp","r",stdin);
    freopen("bai4.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<inr>());
    for(int i=1;i<=m;i++)pq.push(a[i]);
    for(int i=m+1;i<=n;i++){
        inr x=pq.top();
        pq.pop();
        pq.push(x+a[i]);
    }
    inr ans=0;
    while(!pq.empty()){
        ans=max(ans,pq.top());
        pq.pop();
    }
    cout<<ans;
}
