#include<bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("ucln.inp","r",stdin);
    freopen("ucln.out","w",stdout);

    int a,b;
    cin>>a>>b;

    cout<<gcd(a,b);

}

