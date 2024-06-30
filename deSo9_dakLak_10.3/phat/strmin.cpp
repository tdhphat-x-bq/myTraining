#include<bits/stdc++.h>
#define inr long long
#define N 1000006
#define M 1003
using namespace std;
const int li=5e5+1;

int n,x,y,z;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("strmin.inp","r",stdin);
    freopen("strmin.out","w",stdout);

    cin>>n>>x>>y>>z;
    string sx="",sy="",sz="";
    for(int i=0;i<x;i++) sx += char(i%2+65);
    for(int i=0;i<y;i++) sy += char(i%2+97);
    for(int i=0;i<n-x-y;i++) sz += char(i%2+48);
    cout<<sz+sx+sy;
}

