#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr n,ans;
inr a[N];

void sub12(){
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            inr sum = a[i]+a[j];
            inr tmp = lower_bound(a+j+1,a+n+1,sum)-a;
            if(a[tmp] == sum and tmp<=n){
                ans+=2;
            }
        }
    }
}

void sub3(){
    for(int i=3;i<=n;i++){
        ans+=((i-1)/2*2);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ptb2.inp","r",stdin);
    freopen("ptb2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=3000){
        sub12();
    }else{
        sub3();
    }
    cout<<ans;
}
