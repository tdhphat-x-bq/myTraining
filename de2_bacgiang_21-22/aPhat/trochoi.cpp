#include<bits/stdc++.h>
#define int long long
using namespace std;

main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("trochoi.inp","r",stdin);
    freopen("trochoi.out","w",stdout);
    int n;cin>>n;

    int a[n+1],b[n+1];

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    sort(b+1,b+n+1);
    sort(a+1,a+n+1);

    int res=1e18,l=1,r=n;
    while(l<=n && r>0){
        res=min(res,abs(a[l] + b[r]));

        if(res == 0)break;
        if(a[l] + b[r] <0)l++;
        else r--;
    }
    cout<<res;
}

