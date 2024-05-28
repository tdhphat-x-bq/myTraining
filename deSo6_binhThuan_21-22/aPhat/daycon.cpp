#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

int n,m;
int a[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("daycon.inp","r",stdin);
    freopen("daycon.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r,res=0,sum=0;
    for(r=1;r<=n;r++){
        sum+=a[r];
        while(sum>m){
            sum-=a[l];
            l++;
        }
        res+=(r-l+1);
    }
    cout<<res;
}
