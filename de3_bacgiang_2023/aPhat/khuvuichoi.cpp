#include<bits/stdc++.h>
#define int long long
#define N 1000006
#define M 103
using namespace std;

int bd,kt;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("khuvuichoi.inp","r",stdin);
    freopen("khuvuichoi.out","w",stdout);


   cin>>bd>>kt;
   if(bd >= 6 and bd<=12 and kt>=6 and kt<=12){
        if(kt-bd <=4)cout<<(kt-bd)*6;
        else{
            int res= 4*6;
            int tmp=(kt-bd)-4;
            res+=tmp*3;
            cout<<res;
        }
   }else if(bd>=12 and bd<=22 and kt>=12 and kt<=22){
        if(kt-bd <=4)cout<<(kt-bd)*10;
        else{
            int res= 4*10;
            int tmp=(kt-bd)-4;
            res+=tmp*5;
            cout<<res;
        }
   }else{
        int res=0,j=1;
        for(int i=bd+1;i<=kt;i++){
            if(j>4){
                if(i>12 and i<=22){
                    res+=5;
                }else if(i>=6 and i<=12){
                    res+=3;
                }
            }else{
                if(i>12 and i<=22){
                    res+=10;
                }else if(i>=6 and i<=12){
                    res+=6;
                }
            }
            //cout<<res<<endl;
            j++;
        }
        cout<<res;
   }
}

