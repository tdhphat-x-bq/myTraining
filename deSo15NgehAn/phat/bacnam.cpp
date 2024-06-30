#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,ans=1;
inr a[N],pos[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bacnam.inp","r",stdin);
    freopen("bacnam.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n-3;i+=2){
        if(pos[i+2] < pos[i])ans++;
    }
    cout<<ans<<endl;
    ans=1;
    for(int i=2;i<=n-2;i+=2){
        if(pos[i+2]<pos[i])ans++;
    }
    cout<<ans;
}
