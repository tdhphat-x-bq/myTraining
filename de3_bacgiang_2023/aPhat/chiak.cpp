#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define mod 1000000000
using namespace std;

int n,k;
int a[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("chiak.inp","r",stdin);
    freopen("chiak.out","w",stdout);

    cin>>n>>k;

    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i] = (a[i-1] + x + mod * k)%k;
    }
    int res=0,d=1;
    unordered_map<int,int>mp;
    for(int i=1;i<=n+1;i++){
        mp[a[i]] ++;
    }
    for(auto it:mp){
        res += it.second*(it.second-1)/2;
    }
    cout<<res;
}


