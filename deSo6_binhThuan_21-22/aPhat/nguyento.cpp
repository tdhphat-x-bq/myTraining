#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

int n;

bool nt(int n){
    if(n<2)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("nguyento.inp","r",stdin);
    freopen("nguyento.out","w",stdout);

    cin>>n;
    int m=sqrt(n);
    for(int i=m;;i++){
        if(nt(i)){
            cout<<i*i;
            break;
        }
    }
}


