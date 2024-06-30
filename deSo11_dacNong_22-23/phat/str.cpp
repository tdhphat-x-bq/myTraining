#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("str.inp","r",stdin);
    freopen("str.out","w",stdout);

    string s;cin>>s;
    inr cnt=0;
    for(char c:s){
        if(c !='0' and c !='1')cnt++;
    }
    cout<<cnt;
}
