#include <bits/stdc++.h>
#define N 100
using namespace std;
using ll=long long;

main(){
    freopen("in.inp","r",stdin);
    freopen("ou.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int f[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            f[i][j]=INT_MAX;
        }
    }
    f[0][0]=a[0][0];
    for(int i=1;i<m;i++){
        f[0][i]=min(f[0][i-1],a[0][i]);
    }
    for(int i=1;i<n;i++){
        f[i][0]=a[i][0];
        for(int j = 1;j<m;j++){
            for(int k=0;k<i;k++){
                f[i][j] = min({f[i][j],f[i][j-1], a[i][j], f[k][j]+f[i-k-1][j-1]});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<f[i][j]<<" ";
            }cout<<endl;
        }cout<<endl;
    }
    int res=(int)1e18;
    for(int i=0;i<m;i++){
        res=min(res,f[n-1][i]);
    }
    cout<<res<<endl;
    
}
