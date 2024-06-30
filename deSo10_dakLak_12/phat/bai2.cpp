#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define inf 1e18
using namespace std;

inr n,k,b,ans,sum;
inr a[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bai2.inp","r",stdin);
    freopen("bai2.out","w",stdout);
    cin>>n>>k>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    if(b>n){
        int pos1=b%n;
        for(int i=pos1;i<=n and k>0;i++,k--)ans+=a[i];
    }else{
        for(int i=b;i<=n and k>0;i++,k--)ans+=a[i];
    }//step 1

    int pos2=k/n;
    ans+=(sum*pos2);
    // step 2
    int pos3=k-n*pos2;
    for(int i=1;i<=pos3;i++)ans+=a[i];
    //step 3
    cout<<ans;
}

