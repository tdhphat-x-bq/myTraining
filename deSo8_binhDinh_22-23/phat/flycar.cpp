#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define inf 1e18+7
using namespace std;

inr n,k;
inr dp[M][M],h[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("flycar.inp","r",stdin);
    freopen("flycar.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++)dp[i][j]= inf;
    }
    dp[1][0] = 0;
    for(int i=2;i<=n;i++){
        inr s=0,hmax=0;
        for(int j=i;j>0;j--){
            s+=h[j];
            hmax=max(hmax,h[j]);
        }
        dp[i][0] = i*hmax -s;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            inr s=0,hmax=0;
            for(int k=i;k>0;k--){
                s+=h[k];hmax=max(hmax,h[k]);
                dp[i][j] = min(dp[i][j],dp[k-1][j-1] + hmax*(i-k+1)-s);

            }
        }

    }

    cout<<dp[n][k];
}

