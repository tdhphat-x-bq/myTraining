#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define inf 1e18
#define mod 1e9+7
using namespace std;

inr p[N+1],dp[N],a[N];
void sieve(){
    for(int i=2;i<=N;i++)p[i]=1;
    for(int i=2;i<=sqrt(N);i++){
        if(p[i]){
            for(int j=i*i;j<=N;j+=i)p[j]=0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bai1.inp","r",stdin);
    freopen("bai1.out","w",stdout);
    sieve();
    int n=0;
    for(int i=2;i<=1000;i++){
        if(p[i])a[++n]=i;
    }
    fill(dp+1,dp+n+1,-inf);
    for(int i=1;i<=n;i++){
        for(int j=1000;j>=a[i];j--){
            for(int k=1;k<=2;k++){
                if(j>=k*a[i]) dp[j] = max(dp[j],dp[j-k*a[i]]+k);
            }
        }
    }
    while(cin>>n){
        if(n==1)cout<<1;
        else cout<<dp[n];
        cout<<endl;
    }
}
