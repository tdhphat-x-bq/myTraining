#include<bits/stdc++.h>
using namespace std;
#define N 1000006
#define inr long long

inr a[N],imin[N+3];
inr n,ans;
inr cnt[2];

main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    freopen("bitseq.inp","r",stdin);
    freopen("bitseq.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(a[i] == 0) a[i] = a[i-1] -1;
        else a[i] = a[i-1]+1;
        if(a[i] > a[imin[i-1]]) imin[i] = i;
        else imin[i] = imin[i-1];

    }
    ans = cnt[1];
    for(int i=1;i<=n;i++){
        if(imin[i] != i){
            inr a1 = abs(a[i] - a[imin[i]]),b1 = abs(i - imin[i]);
            inr x = (a1+b1)/2,y = b1-x;
            ans=max(ans,cnt[1] - y +x);
        }
    }
    cout<<ans;
}


// 18
// 1 1 0 0 1 1 0 0 1 0 0 0 1 0 0 1 0 0



