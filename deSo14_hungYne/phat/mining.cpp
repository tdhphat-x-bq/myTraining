#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,s,ans=inf;
inr a[N];

bool check(inr m){
    if(m>a[1])return false;
    inr sum=0;
    for(int i=1;i<=n and a[i]>m;i++){
        sum+=(a[i]-m);
    }
    if(sum >= s)return true;
    else return false;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("mining.inp","r",stdin);
    freopen("mining.out","w",stdout);

    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,greater<inr>());
    inr l=0,r=1e9+1;
    while(l<=r){
        inr m=(l+r)/2;
        if(check(m)){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    cout<<ans;
}
