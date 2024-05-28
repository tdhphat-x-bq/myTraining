#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("multiple.inp","r",stdin);
    freopen("multiple.out","w",stdout);

    int n,q;
    cin>>n>>q;
    int res=1,lt=1;
    for(int i=1;i<n;i++){
        lt = (lt*q)%2023;
        res = (res+lt)%2023;

    }
    cout<<res;
}
