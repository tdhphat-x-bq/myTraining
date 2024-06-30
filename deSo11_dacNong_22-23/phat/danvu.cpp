#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,m,ans;
inr a[N],b[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("danvu.inp","r",stdin);
    freopen("danvu.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    inr l=1,r=1;
    while(l<=n and r<=m){
        if(a[l]>b[r]){
            l++;
            r++;
            ans++;
        }else l++;
    }
    cout<<ans;
}
