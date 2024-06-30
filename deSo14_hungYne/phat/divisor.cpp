#include<bits/stdc++.h>
#define inr long long
#define N 3000006
#define M 1003
#define mod 123456789
#define inf 1e18
using namespace std;

inr n,ans=1;
inr a[N],p[3*N];

void pt(inr x){
    for(int i=2;i<=sqrt(x);i++){
        while(x%i==0){
            p[i]++;
            x/=i;
        }
    }
    if(x>1)p[x]++;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("divisor.inp","r",stdin);
    freopen("divisor.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)pt(a[i]);
    }
    for(int i=2;i<=N;i++){
        ans=(ans*(p[i]+1)*1LL)%mod;
    }
    cout<<ans;
}
