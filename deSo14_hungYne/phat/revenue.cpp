#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr x,y,n,ans;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("revenue.inp","r",stdin);
    freopen("revenue.out","w",stdout);

    cin>>x>>y>>n;
    inr tmp = n/7;
    ans+=(x*5+y*2);
    ans*=tmp;
    n-=(tmp*7);
    ans+=y;
    n--;
    if(n==6)ans+=(x*5+y);
    else{
        ans+=(x*n);
    }
    cout<<ans;
}
