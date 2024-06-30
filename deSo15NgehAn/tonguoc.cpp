#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
#define mod 1e9+7
#define inf 1e18
using namespace std;

inr a,b;



main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tonguoc.inp","r",stdin);
    freopen("tonguoc.out","w",stdout);
    cin>>a>>b;
    inr ans=0;
    for(int i=1;i<=sqrt(a);i++){
        if(a%i==0){
            if(b%(3*i)==0){
                ans+=i;
            }
            if(i!=sqrt(a) and b%(3*(a/i))==0){
                ans+=a/i;
            }
        }
    }
    cout<<ans;
}
