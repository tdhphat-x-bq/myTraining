#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

struct den{
    inr tat,xanh;
};

inr n,m,s;
vector<vector<inr>>a;
inr t[N];
den d[N];

inr solve1(){
    for(int i=1;i<=s;i++){
        if(t[i]>n)break;
        for(int j=1;j<=m;j++){
            a[t[i]][j]=(a[t[i]][j]+1)%3;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[j][i] == 0)d[i].tat++;
            else if(a[j][i] == 1)d[i].xanh++;
        }
    }
    //for(int i=1;i<=m;i++)cout<<d[i].tat<<" "<<d[i].xanh<<endl;
    for(int i=s;i>0;i--){
        if(t[i]<=n)break;
        inr k=t[i]-n;
        inr red=n-(d[k].tat+d[k].xanh);
        d[k].xanh = d[k].tat;
        d[k].tat = red;
    }
    inr ans=0;
    for(int i=1;i<=m;i++)ans+=d[i].tat;
    return ans;
}

inr solve2(){
    for(int i=s;i>0;i--){
        if(t[i]<=n)break;
        inr k=t[i]-n;
        for(int j=1;j<=n;j++){
            a[j][k]=(a[j][k]+1)%3;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++)cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 0)d[i].tat++;
            else if(a[i][j] == 1)d[i].xanh++;
        }
    }
    //for(int i=1;i<=m;i++)cout<<d[i].tat<<" "<<d[i].xanh<<endl;
    for(int i=1;i<=s;i++){
        if(t[i]>n)break;
        inr k=t[i];
        inr red=m-(d[k].tat+d[k].xanh);
        d[k].xanh = d[k].tat;
        d[k].tat = red;
    }
    inr ans=0;
    for(int i=1;i<=n;i++)ans+=d[i].tat;
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("dieukhien.inp","r",stdin);
    freopen("dieukhien.out","w",stdout);

    cin>>n>>m>>s;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        a[i].resize(m+1);
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    for(int i=1;i<=s;i++)cin>>t[i];
    sort(t+1,t+s+1);
    if(n>m)cout<<solve1();
    else cout<<solve2();
}
