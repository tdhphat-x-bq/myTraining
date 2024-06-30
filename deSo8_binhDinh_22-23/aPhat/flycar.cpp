#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,k;
inr a[N],dp[M][M];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("flycar.inp","r",stdin);
    freopen("flycar.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++)dp[i][j]=inf;
    }
    dp[1][0] = 0;
    for(int i=2;i<=n;i++){
        inr sum=0,am=0;
        for(int j=i;j>0;j--){
            sum+=a[j];
            am=max(am,a[j]);
        }
        dp[i][0] = i*am-sum;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            inr sum=0,am=0;
            for(int k=i;k>0;k--){
                sum+=a[k];am=max(am,a[k]);
                dp[i][j]=min(dp[i][j],dp[k-1][j-1]+(i-k+1)*am-sum);
            }
        }
    }
    cout<<dp[n][k];
}
