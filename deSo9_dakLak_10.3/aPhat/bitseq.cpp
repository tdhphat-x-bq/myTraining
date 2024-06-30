#include<bits/stdc++.h>
using namespace std;
#define N 1000006
#define inr long long

inr n;
inr a[N],imin[N];
inr cnt[2];

main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    freopen("bitseq.inp","r",stdin);
    freopen("bitseq.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        inr x;cin>>x;
        cnt[x]++;
        if(x == 1)a[i]=a[i-1]+1;
        else a[i] = a[i-1]-1;
        if(a[imin[i-1]] < a[i])imin[i]=i;
        else imin[i]=imin[i-1];
    }
    inr ans=0;
    for(int i=1;i<=n;i++){
        if(imin[i] != i){
            inr a1=abs(a[i]-a[imin[i]]),b1=i-imin[i];
            inr x=(a1+b1)/2,y=b1-x;
            ans=max(ans,cnt[1]-y+x);
        }
    }
    cout<<ans;
}






