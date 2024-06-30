#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,s,sum,ans,cake;
inr a[N],b[N];
priority_queue<inr>pq;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("birthday.inp","r",stdin);
    freopen("birthday.out","w",stdout);

    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        sum+=b[i];
        pq.push(b[i]);
        cake++;
        while(!pq.empty() and sum+a[i]>s){
            sum-=pq.top();
            pq.pop();
            cake--;
        }
        ans=max(ans,cake);
    }
    cout<<ans;
}
