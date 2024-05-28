#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

int n,k,res;
int a[N];
unordered_map<int,int>mp;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("teracing.inp","r",stdin);
    freopen("teracing.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
   // sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int x=a[i] + k;
        if(mp[x] != 0){
            res+=mp[x];
        }
    }
    cout<<res;
}

