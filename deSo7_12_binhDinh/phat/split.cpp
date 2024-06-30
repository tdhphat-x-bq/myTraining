#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,m,k;
string s,t;
inr f[M][M];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("split.inp","r",stdin);
    freopen("split.out","w",stdout);
    cin>>n>>m>>t;
    cin>>s>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                f[i][j] = f[i-1][j-1]+1;
            }else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    if(f[n][m] != 0)cout<<f[n][m];
    else cout<<-1;
}
