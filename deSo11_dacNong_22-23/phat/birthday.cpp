#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,t,ans,cake;
inr a[N],b[N];
inr sum;
priority_queue<inr>pq;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("birthday.inp","r",stdin);
    freopen("birthday.out","w",stdout);

    cin>>n>>t;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        cake++;
        sum+=b[i];
        pq.push(b[i]);
        while(!pq.empty() and sum+a[i] > t){
            sum-=pq.top();
            pq.pop();
            cake--;
        }
        ans=max(ans,cake);
    }
    cout<<ans;
}
