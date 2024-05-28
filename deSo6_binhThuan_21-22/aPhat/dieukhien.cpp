#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 1003
using namespace std;

int m,n,s;
int t[N];
vector<vector<int>>a;

struct handle{
    int tat,xanh;
};

handle hang[N],cot[N];

int solve1(){
    for(int i=s;i>0;i--){
        if(t[i]<=m)break;
        int k=t[i]-m;
        for(int j=1;j<=m;j++){
            a[j][k] = (a[j][k]+1)%3;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == 0)hang[i].tat++;
            else if(a[i][j] == 1)hang[i].xanh++;
        }
    }
    for(int i=1;i<=s;i++){
        if(t[i]>m)break;
        int red=n-(hang[t[i]].tat+hang[t[i]].xanh);
        hang[t[i]].xanh = hang[t[i]].tat;
        hang[t[i]].tat = red;
    }
    int res=0;
    for(int i=1;i<=m;i++){
        res+=hang[i].tat;
    }
    return res;
}

int solve2(){
    for(int i=1;i<=s;i++){
        if(t[i] > m)break;
        for(int j=1;j<=n;j++){
            a[t[i]][j] = (a[t[i]][j] +1)%3;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[j][i] == 0)cot[i].tat++;
            else if(a[j][i] == 1)cot[i].xanh++;
        }
    }
    for(int i=s;i>0;i--){
        if(t[i] <= m)break;
        int k=t[i]-m;
        int red = m-(cot[k].tat+cot[k].xanh);
        cot[k].xanh = cot[k].tat;
        cot[k].tat = red;
    }
    int res=0;
    for(int i=1;i<=n;i++)res+=cot[i].tat;
    return res;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("dieukhien.inp","r",stdin);
    freopen("dieukhien.out","w",stdout);

    cin>>m>>n>>s;
    a.resize(m+2);
    for(int i=1;i<=m;i++){
        a[i].resize(n+2);
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=s;i++){
        cin>>t[i];
    }
    sort(t+1,t+s+1);
    if(n>=m){
        cout<<solve1();
    }else{
        cout<<solve2();
    }
}

